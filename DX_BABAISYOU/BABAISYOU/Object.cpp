#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"
#include "MapManager.h"
#include  <map>

AObject::AObject()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	SetRoot(Root);

	Root->AddScale(FVector(54, 54, 1));

	Info = new ObjectInfo();
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();
}

void AObject::BeginPosSetting()
{
	// 움직일 애들 Location 설정해주고나서 다시 해줘야함.
	CurActorLocation = GetActorLocation();
	Info->CurIndex = CalPosToIndex(CurActorLocation);
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

// 나를 _Cur위치에서 지우고 _Next위치로 데이터 상 옮겨주는 함수. 
void AObject::CurToNext(FVector _Cur, FVector _Next)
{
	Index2D CurI = Info->CurIndex;
	Index2D NxtI = CalPosToIndex(_Next);

	// Info 바꿔주기
	Info->CurIndex = NxtI;

	// GMM의 Graph 원래 있던 곳에서 지우기
	//std::list<AObject*> ObjLst = GMapManager->Graph[CurI.X][CurI.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[CurI.X][CurI.Y].begin(); Iter != GMapManager->Graph[CurI.X][CurI.Y].end(); Iter++)
	{
		if (*Iter == static_cast<AObject*>(this))
		{
			GMapManager->Graph[CurI.X][CurI.Y].remove(*Iter);
			break;
		}
	}

	// GMM의 Graph 새 위치에 넣어주기
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

// _Dir 방향의 _Next칸에 쭉 밀 수 있는지 "체크"하는 함수
bool AObject::CanGoNextAll(Index2D _Next, EInputDir _Dir)
{
	// 못 옮기는 경우 1. 벽 넘어감
	if (true == IndexRangeOverCheck(_Next))
	{
		return false;
	}

	// _Next에 갈 수 없는지 하나씩 보고 체크해야 함
	//std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		// 못 옮기는 경우 2. 다음 블록이 못 옮기는 블록.
		if ((*Iter)->Info->ObjectiveType == EObjectType::STOP)
		{
			return false;
		}
		if (
			(*Iter)->Info->ObjectiveType == EObjectType::PUSH ||
			(*Iter)->Info->TileType == ETileType::Subject ||
			(*Iter)->Info->TileType == ETileType::Verb || 
			(*Iter)->Info->TileType == ETileType::Objective
			)
		{
			// PUSH인 애는 그 옆도 계속 체크.
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
				NextNext.Y += 1;
				break;
			case EInputDir::Down:
				NextNext.Y -= 1;
				break;
			default:
				break;
			}

			if (false == (*Iter)->CanGoNextAll(NextNext, _Dir))
			{
				return false;
			}
		}
	}

	// 하나도 안 걸렸으면 이동 가능.
	return true;
}

// 옆 칸이 PUSH인지 확인하는 함수
bool AObject::IsNextPUSH(Index2D _Next)
{
	//std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		if (
			(*Iter)->Info->ObjectiveType == EObjectType::PUSH ||
			(*Iter)->Info->TileType == ETileType::Subject ||
			(*Iter)->Info->TileType == ETileType::Verb ||
			(*Iter)->Info->TileType == ETileType::Objective
			)
		{
			return true;
		}
	}

	return false;
}

// _Dir 방향의 _Next칸에 밀기(진짜 밀기 행동)(밀 수 있는 경우에만 사용해야 함)
void AObject::AllPushNextTile(Index2D _Next, EInputDir _Dir)
{
	std::list<std::pair<AObject*, Index2D>> PushList;
	//std::map<AObject*, Index2D> PushList;

	//std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		// PUSH인 애는 그 옆도 계속 밀어주기.
		if (
			(*Iter)->Info->ObjectiveType == EObjectType::PUSH ||
			(*Iter)->Info->TileType == ETileType::Subject ||
			(*Iter)->Info->TileType == ETileType::Verb ||
			(*Iter)->Info->TileType == ETileType::Objective
			)
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
				NextNext.Y += 1;
				break;
			case EInputDir::Down:
				NextNext.Y -= 1;
				break;
			default:
				break;
			}

			PushList.push_back(std::make_pair(*Iter, NextNext));
			//PushList[*Iter] = NextNext;
			(*Iter)->AllPushNextTile(NextNext, _Dir);
		}
	}

	for (auto PO : PushList)
	{
		PO.first->CurToNext(CalIndexToPos(_Next), CalIndexToPos(PO.second));
		PO.first->NewInputDir = _Dir;
	}
}

void AObject::PushTrueHistory()
{
	MoveStack.push(std::make_pair(NewInputDir, true));
	AnimationStack.push(std::make_pair((AnimationNumber - 1 + 4) % 4, BeforeDir));
	int a = 0;
}

void AObject::PushFalseHistory()
{
	MoveStack.push(std::make_pair(NewInputDir, false));
}

bool AObject::DirCheck()
{
	if (CurDir != NewInputDir)
	{
		CurDir = NewInputDir;
		return true;
	}
	return false;
}