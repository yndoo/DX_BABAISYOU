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

		bool CanGoBack = get<2>(MoveStack.top());		// Ʃ�� �� ��° ����	
		if (false == get<2>(MoveStack.top()))
		{
			// �ڷ� ���ư� �� ���� �ѹ��� false�� �ѱ�� �ȴ�.
			ReverseMoveSetting(NewInputDir, _DeltaTime, false);
			MoveStack.pop();
			return;
		}


		// �̵� : ���� ������ �ݴ�� �̵�
		ReverseMoveSetting(NewInputDir, _DeltaTime, true);

		// �ִϸ��̼ǿ� �ʿ��� ���� : ���� ������ ������ �ǵ����� ����
		NewInputDir = get<1>(MoveStack.top());		// Ʃ�� �� ��° ����	
		AnimationNumber = get<0>(MoveStack.top());	// Ʃ�� ù ��° ����
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
			Index2D Idx = CalPosToIndex(NextActorLocation);
			Index2D MaxIdx = Index2D(UContentsConstValue::MaxIndexX, UContentsConstValue::MaxIndexY);
			if (Idx.X < 0 || Idx.Y < 0 || Idx.X > MaxIdx.X || Idx.Y > MaxIdx.Y)
			{
				// �̵� ���� �Էµ� ���ÿ� �־���.
				MoveStack.push(std::make_tuple(AnimationNumber, CurDir, false));
				IsMove = false;
				NewInputDir = CurDir;	// �Է� ���� �� �� ��� NewInputDir �ٽ� �ǵ���������
				return;
			}
			// �Է� ���� OK
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

		// GMapManager->Graph���� �Ű��ֱ�
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

	// �ִϸ��̼� "����"�� ���������� ��.
	// �̵��� �ݴ��.
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

void ALerpMoveObject::CurToNext(FVector _Cur, FVector _Next)
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