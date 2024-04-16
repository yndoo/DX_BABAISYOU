#include "PreCompile.h"
#include "LerpMoveObject.h"
#include "ContentsConstValue.h"
#include "MapManager.h"
#include <EngineCore/EngineDebugMsgWindow.h>

//int ALerpMoveObject::SomeMoveCnt = 0;
//int ALerpMoveObject::SomeStayCnt = 0;
//int ALerpMoveObject::CurLerpObjCnt = 0;

ALerpMoveObject::ALerpMoveObject()
{
	 //InputOn();
}

ALerpMoveObject::~ALerpMoveObject()
{
}

void ALerpMoveObject::BeginPlay()
{
	Super::BeginPlay();
}

void ALerpMoveObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	InputMove(_DeltaTime);
	if (true == IsMove)
	{
		LerpMove(_DeltaTime);
	}

	if (true == IsDown('Z') && false == IsMove)
	{
		if (true == MoveStack.empty())
		{
			return;
		}
		
		IsMove = true;
		ZInputCheck = true;

		bool CanGoBack = get<2>(MoveStack.top());		// 튜플 세 번째 원소	
		if (false == get<2>(MoveStack.top()))
		{
			// 뒤로 돌아갈 수 없는 롤백은 false로 넘기면 된다.
			ReverseMoveSetting(NewInputDir, _DeltaTime, false);
			MoveStack.pop();
			return;
		}


		// 이동 : 현재 방향의 반대로 이동
		ReverseMoveSetting(NewInputDir, _DeltaTime, true);

		// 애니메이션에 필요한 정보 : 이전 상태의 정보로 되돌리고 삭제
		NewInputDir = get<1>(MoveStack.top());		// 튜플 두 번째 원소	
		AnimationNumber = get<0>(MoveStack.top());	// 튜플 첫 번째 원소
		MoveStack.pop();
		return;
	}

	if (true == EachInputCheck)
	{
		MoveStack.push(std::make_tuple(AnimationNumber, CurDir, true));
		int a = 0;
	}

}

void ALerpMoveObject::InputMove(float _DeltaTime)
{
	if (false == IsMove)
	{
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
			if (false == CanGoNextTile(Idx, NewInputDir)) // STOP블록이거나 벽이면 막힘
			{
				// 이동 막힌 입력도 스택에 넣어줌. (아무도 이동 안 한거면 넣을 필요가 없는데...)
				MoveStack.push(std::make_tuple(AnimationNumber, CurDir, false));
				IsMove = false;
				NewInputDir = CurDir;	// 입력 적용 안 된 경우 NewInputDir 다시 되돌려놔야함
				return;
			}
			// PUSH있으면 밀기
			if (true == IsNextPUSH(Idx))
			{
				if (true == CanGoNextAll(Idx, NewInputDir))
				{
					AllPushNextTile(Idx, NewInputDir);
				}
				else
				{
					// 이동 막힌 입력도 스택에 넣어줌. (아무도 이동 안 한거면 넣을 필요가 없는데...)
					MoveStack.push(std::make_tuple(AnimationNumber, CurDir, false));
					IsMove = false;
					NewInputDir = CurDir;	// 입력 적용 안 된 경우 NewInputDir 다시 되돌려놔야함
					return;
				}
			}

			// 입력 적용 OK
			EachInputCheck = true;
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
		LerpTime += _DeltaTime * 3;
		SetActorLocation(LerpCal(LerpTime));
	}
	else
	{
		IsMove = false;
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
}