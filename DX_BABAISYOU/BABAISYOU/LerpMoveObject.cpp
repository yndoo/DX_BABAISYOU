#include "PreCompile.h"
#include "LerpMoveObject.h"
#include "ContentsConstValue.h"
#include "MapManager.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include "FootPrint.h"

//int ALerpMoveObject::SomeMoveCnt = 0;
//int ALerpMoveObject::SomeStayCnt = 0;
//int ALerpMoveObject::CurLerpObjCnt = 0;

ALerpMoveObject::ALerpMoveObject()
{
	 InputOn();
}

ALerpMoveObject::~ALerpMoveObject()
{
}

void ALerpMoveObject::BeginPlay()
{
	Super::BeginPlay();
}

// 입력 외에 위치 변화가 있는 애들 진짜 행동으로 움직여주는 함수 (Push 당한 애들 등등)
void ALerpMoveObject::PushedUpdate(float _DeltaTime)
{
	if (false == IsMove)
	{
		Index2D Cur = Info->CurIndex;
		Index2D Before = CalPosToIndex(GetActorLocation());
		if (Cur != Before)
		{
			IsMove = true;
			EachMoveCheck_ForStack = true;
			AddNextActorLocation(CalIndexToPos(Cur) - CalIndexToPos(Before));
		}
	}
}

void ALerpMoveObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (Info->MyType == EObjectType::BABA)
	{
		int a = 0;
	}

	// Input이동은 안 되지만 Z는 되어야 하는 경우가 있음. YOU인 경우에만 InputMove
	if (false == IsMove)
	{
		PushedUpdate(_DeltaTime);
		if (Info->TileType == ETileType::Player && Info->MyObjectiveType[EObjectType::YOU] == true)
		{
			InputMove(_DeltaTime);
		}
	}

	if (true == IsMove)
	{
		LerpMove(_DeltaTime);
		return;
	}

	if (true == IsDown('Z') && false == IsMove)
	{
		if (true == MoveStack.empty())
		{
			return;
		}
		

		IsMove = true;
		ZInputCheck = true;
		UContentsConstValue::ZInput = true;
		UContentsConstValue::InputCount++;

		bool CanGoBack = MoveStack.top().second;
		if (false == CanGoBack)
		{
			// 뒤로 돌아갈 수 없는 롤백은 false로 넘기면 된다.
			ReverseMoveSetting(NewInputDir, _DeltaTime, false);
			MoveStack.pop();
			return;
		}

		// 뒤로 돌아가야 하는 롤백
		// 
		// 1. 이동 : 현재 방향의 반대로 이동
		ReverseMoveSetting(MoveStack.top().first, _DeltaTime, true);

		// 2. 애니메이션에 필요한 정보 : 이전 상태의 정보로 되돌리고 삭제
		AnimationNumber = AnimationStack.top().first;
		NewInputDir = AnimationStack.top().second;


		MoveStack.pop();
		AnimationStack.pop();

		return;
	}
}

void ALerpMoveObject::InputMove(float _DeltaTime)
{
	if (false == IsMove)
	{
		BeforeDir = CurDir;	// 이전 방향

		if (true == IsDown(VK_LEFT))
		{
			AddNextActorLocation(FVector::Left * TileSize);
			NewInputDir = EInputDir::Left;
			IsMove = true;
		}

		if (true == IsDown(VK_RIGHT))
		{
			AddNextActorLocation(FVector::Right * TileSize);
			NewInputDir = EInputDir::Right;
			IsMove = true;
		}

		if (true == IsDown(VK_UP))
		{
			AddNextActorLocation(FVector::Up * TileSize);
			NewInputDir = EInputDir::Up;
			IsMove = true;
		}

		if (true == IsDown(VK_DOWN))
		{
			AddNextActorLocation(FVector::Down * TileSize);
			NewInputDir = EInputDir::Down;
			IsMove = true;
		}
		if (true == IsMove)
		{
			// 1. 벽에 안 막히는 지 확인
			// 2. 이동할 곳의 방향에 옮길 수 없는 오브젝트가 하나라도 있는 지 확인해야 함.
			Index2D Idx = CalPosToIndex(NextActorLocation);
			if (false == CanGoNextAll(Idx, NewInputDir) || true == Destroyed) // STOP블록이거나 벽이거나 파괴 상태면 막힘
			{
				IsMove = false;
				NewInputDir = CurDir;	// 입력 적용 안 된 경우 NewInputDir 다시 되돌려놔야함
				return;
			}
			// PUSH있으면 밀기
			if (true == IsNextPUSH(Idx))
			{
				AllPushNextTile(Idx, NewInputDir);
			}

			// 입력 적용 OK
			UContentsConstValue::InputCount++;
			EachMoveCheck_ForStack = true;
			EachInputCheck = true;

			if(EObjectType::BABA == Info->MyType)
			{
				std::shared_ptr<AFootPrint> footprint = GetWorld()->SpawnActor<AFootPrint>("footprint");
				footprint->SetActorLocation(GetActorLocation());
			}
		}
	}
	//LerpMove(_DeltaTime);
}

void ALerpMoveObject::AddNextActorLocation(FVector _Add)
{
	NextActorLocation = GetActorLocation() + _Add;
}

void ALerpMoveObject::LerpMove(float _DeltaTime)
{
	if (LerpTime <= 1.f && true == IsMove)
	{
		LerpTime += _DeltaTime * 6;
		SetActorLocation(LerpCal(LerpTime));
	}
	else
	{
		IsMove = false;
		EachMoveCheck_ForStack = false;
		LerpTime = 0.f;
		SetActorLocation(NextActorLocation);

		// GMapManager->Graph에서 옮겨주기
		CurToNext(CurActorLocation, NextActorLocation);

		CurActorLocation = NextActorLocation;
	}
}

FVector ALerpMoveObject::LerpCal(float _Time)
{
	return CurActorLocation * (1 - _Time) + NextActorLocation * _Time;
}

void ALerpMoveObject::ReverseMoveSetting(EInputDir _Dir, float _DeltaTime, bool _CanMove)
{
	IsMove = true;

	if (false == _CanMove)
	{
		AddNextActorLocation(FVector::Zero);
		return;
	}

	// 애니메이션 "방향"은 이전꺼여야 함.
	// 이동은 반대로.
	switch (_Dir)
	{
	case EInputDir::Right:
		AddNextActorLocation(FVector::Left * TileSize);
		NewInputDir = EInputDir::Right;	
		break;
	case EInputDir::Left:
		AddNextActorLocation(FVector::Right * TileSize);
		NewInputDir = EInputDir::Left;
		break;
	case EInputDir::Up:
		AddNextActorLocation(FVector::Down * TileSize);
		NewInputDir = EInputDir::Up;
		break;
	case EInputDir::Down:
		AddNextActorLocation(FVector::Up * TileSize);
		NewInputDir = EInputDir::Down;
		break;
	default:
		AddNextActorLocation(FVector::Zero);
		break;
	}

	CurToNext(CurActorLocation, NextActorLocation);
}
