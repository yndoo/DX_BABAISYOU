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

// 범위 넘어가는지 체크. true : 넘어감
bool AObject::IndexRangeOverCheck(Index2D Idx)
{
	if (Idx.X < 0 || Idx.Y < 0 || Idx.X > UContentsConstValue::MaxIndexX || Idx.Y > UContentsConstValue::MaxIndexY)
	{
		return true;
	}

	return false;
}

// _Dir 방향의 _Next칸에 목적어 타입이 PUSH인 애가 있으면 쭉 그 방향 체크
bool AObject::PushCheck(Index2D _Next, EInputDir _Dir)
{
	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		if ((*Iter)->Info->Objective == EObjectiveType::STOP)
		{
			return false;
		}
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
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
			// 못 옮기는 경우 2. 다음 블록이 못 옮기는 블록.
			if (false == (*Iter)->PushCheck(NextNext, _Dir))
			{
				return false;
			}
		}
	}

	// 하나도 안 걸렸으면 PUSH 가능.
	return true;
}