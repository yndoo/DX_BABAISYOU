#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"
#include "MapManager.h"

AObject::AObject()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	SetRoot(Root);
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();

	Info = new ObjectInfo();
}

Index2D AObject::CalPosToIndex(FVector _Pos)
{
	Index2D Index;

	// 인덱스 다같이 왼쪽 아래로 땡기려면 좌표를 오른쪽 위로 땡긴다고 생각하고 정리
	_Pos.X += MapScale.hX();	
	_Pos.Y += MapScale.hY();

	_Pos -= FVector(UContentsConstValue::ITileX / 2, UContentsConstValue::ITileY / 2);

	Index.X = _Pos.X / UContentsConstValue::ITileX;
	Index.Y = _Pos.Y / UContentsConstValue::ITileY;


	return Index;
}

FVector AObject::CalIndexToPos(Index2D _Index)
{
	if (MapScale.X == 0 && MapScale.Y == 0)
	{
		MsgBoxAssert("MapScale이 0, 0임");
	}

	FVector Pos = FVector::Zero;
	Pos.X -= MapScale.hX();
	Pos.Y -= MapScale.hY();

	Pos.X += _Index.X * UContentsConstValue::ITileX;
	Pos.Y += _Index.Y * UContentsConstValue::ITileY;

	Pos += FVector(UContentsConstValue::ITileX / 2, UContentsConstValue::ITileY / 2);

	return Pos;
}

Index2D AObject::GetMaxIndex()
{
	Index2D Result;
	Result.X = MapScale.iX() / UContentsConstValue::ITileX - 1;
	Result.Y = MapScale.iY() / UContentsConstValue::ITileY - 1;

	return Result;
}

void AObject::SetMaxIndex()
{
	Index2D MaxIndex = GetMaxIndex();

	UContentsConstValue::MaxIndexX = MaxIndex.X;
	UContentsConstValue::MaxIndexY = MaxIndex.Y;
}

// 나를 _Cur위치에서 지우고 _Next위치로 옮겨주는 함수.
void AObject::CurToNext(FVector _Cur, FVector _Next)
{
	Index2D CurI = CalPosToIndex(_Cur);
	Index2D NxtI = CalPosToIndex(_Next);

	std::list<AObject*> ObjLst = GMapManager->Graph[CurI.X][CurI.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		if (*Iter == static_cast<AObject*>(this))
		{
			GMapManager->Graph[CurI.X][CurI.Y].remove(this);
			break;
		}
	}

	GMapManager->Graph[NxtI.X][NxtI.Y].push_back(static_cast<AObject*>(this));
}


// 범위 넘어가는지 체크. true : 넘어감
bool AObject::IndexRangeOverCheck(Index2D Idx)
{
	if (Idx.X < 0 || Idx.Y < 0 || Idx.X > UContentsConstValue::MaxIndexX || Idx.Y > UContentsConstValue::MaxIndexY)
	{
		return true;
	}

	return false;
}

// _Dir 방향의 _Next칸에 갈 수 있는지 체크하는 함수
bool AObject::CanGoNextTile(Index2D _Next, EInputDir _Dir)
{
	// 못 옮기는 경우 1. 벽 넘어감
	if (true == IndexRangeOverCheck(_Next))
	{
		return false;
	}

	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		// 못 옮기는 경우 2. 못 옮기는 블록.
		if ((*Iter)->Info->Objective == EObjectiveType::STOP)
		{
			return false;
		}
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
		{
			// PUSH인 애는 어캄?
			// AllPushNextTile 결과가 true면 밀어주고 끝?
		}
	}

	// 위에서 하나도 안 걸렸으면 이동 가능.
	return true;
}

// _Dir 방향의 _Next칸에 쭉 갈 수 있는지 "체크"하는 함수
bool AObject::CanGoNextAll(Index2D _Next, EInputDir _Dir)
{
	Index2D NextNext = _Next;
	switch (_Dir)
	{
	case EInputDir::Right:
		NextNext.X += 1;
		break;
	case EInputDir::Left:
		NextNext.X -= 1;
		break;
	case EInputDir::Up:
		NextNext.Y -= 1;
		break;
	case EInputDir::Down:
		NextNext.Y -= 1;
		break;
	default:
		break;
	}

	// 못 옮기는 경우 1. 벽 넘어감
	if (true == IndexRangeOverCheck(NextNext))
	{
		return false;
	}

	// _Next에 갈 수 없는지 하나씩 보고 체크해야 함
	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		// 못 옮기는 경우 2. 다음 블록이 못 옮기는 블록.
		if ((*Iter)->Info->Objective == EObjectiveType::STOP)
		{
			return false;
		}
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
		{
			// PUSH인 애는 그 옆도 계속 체크.
			if (false == (*Iter)->CanGoNextAll(NextNext, _Dir))
			{
				return false;
			}
		}
	}

	// 하나도 안 걸렸으면 이동 가능.
	return true;
}

// _Dir 방향의 _Next칸에 밀기(진짜 밀기 행동)(밀 수 있는 경우에만 사용해야 함)
void AObject::AllPushNextTile(Index2D _Next, EInputDir _Dir)
{
	Index2D NextNext = _Next;
	switch (_Dir)
	{
	case EInputDir::Right:
		NextNext.X += 1;
		break;
	case EInputDir::Left:
		NextNext.X -= 1;
		break;
	case EInputDir::Up:
		NextNext.Y -= 1;
		break;
	case EInputDir::Down:
		NextNext.Y -= 1;
		break;
	default:
		break;
	}

	// 얘는 벽넘어가는거 말고는 언제 막아줘야하지?
	if (true == IndexRangeOverCheck(NextNext))
	{
		return;
	}

	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		// PUSH인 애는 그 옆도 계속 밀어주기.
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
		{
			(*Iter)->AllPushNextTile(NextNext, _Dir);
		}
	}

	CurToNext(CalIndexToPos(_Next), CalIndexToPos(NextNext));
}