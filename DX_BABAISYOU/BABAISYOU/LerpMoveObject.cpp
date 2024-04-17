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
	 InputOn();
}

ALerpMoveObject::~ALerpMoveObject()
{
}

void ALerpMoveObject::BeginPlay()
{
	Super::BeginPlay();
}

// �Է� �ܿ� ��ġ ��ȭ�� �ִ� �ֵ� ��¥ �ൿ���� �������ִ� �Լ� (Push ���� �ֵ� ���)
void ALerpMoveObject::Update(float _DeltaTime)
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
			//NewInputDir = CurDir;
			//PushTrueHistory();
		}
	}
}

void ALerpMoveObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	// Input�̵��� �� ������ Z�� �Ǿ�� �ϴ� ��찡 ����. YOU�� ��쿡�� InputMove
	if (false == IsMove)
	{
		Update(_DeltaTime);
		if (Info->ObjectiveType == EObjectType::YOU)
		{
			InputMove(_DeltaTime);
		}
	}

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


		bool CanGoBack = MoveStack.top().second;		// Ʃ�� �� ��° ����	
		if (false == CanGoBack)
		{
			// �ڷ� ���ư� �� ���� �ѹ��� false�� �ѱ�� �ȴ�.
			ReverseMoveSetting(NewInputDir, _DeltaTime, false);
			MoveStack.pop();
			return;
		}

		// �ڷ� ���ư��� �ϴ� �ѹ�
		// 1. �̵� : ���� ������ �ݴ�� �̵�
		ReverseMoveSetting(MoveStack.top().first, _DeltaTime, true);

		// 2. �ִϸ��̼ǿ� �ʿ��� ���� : ���� ������ ������ �ǵ����� ����
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
		BeforeDir = CurDir;	// ���� ����

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
			// 1. ���� �� ������ �� Ȯ��
			// 2. �̵��� ���� ���⿡ �ű� �� ���� ������Ʈ�� �ϳ��� �ִ� �� Ȯ���ؾ� ��.
			Index2D Idx = CalPosToIndex(NextActorLocation);
			if (false == CanGoNextAll(Idx, NewInputDir)) // STOP����̰ų� ���̸� ����
			{
				IsMove = false;
				NewInputDir = CurDir;	// �Է� ���� �� �� ��� NewInputDir �ٽ� �ǵ���������
				return;
			}
			// PUSH������ �б�
			if (true == IsNextPUSH(Idx))
			{
				if (true == CanGoNextAll(Idx, NewInputDir))
				{
					AllPushNextTile(Idx, NewInputDir);
				}
				else
				{
					IsMove = false;
					NewInputDir = CurDir;	// �Է� ���� �� �� ��� NewInputDir �ٽ� �ǵ���������
					return;
				}
			}

			// �Է� ���� OK
			UContentsConstValue::InputCount++;
			EachMoveCheck_ForStack = true;
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
		EachMoveCheck_ForStack = false;
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
