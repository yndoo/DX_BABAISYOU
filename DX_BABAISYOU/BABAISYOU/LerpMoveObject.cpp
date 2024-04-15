#include "PreCompile.h"
#include "LerpMoveObject.h"
#include "ContentsConstValue.h"

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

	//if (true == IsMove && true == LerpStarted)
	//{
	//	MoveStack.push(std::make_tuple(AnimationNumber, CurDir, false));
	//}
	//if (true == IsMove)
	//{
	//	MoveStack.push(std::make_tuple(AnimationNumber, CurDir, true));
	//	LerpMove(_DeltaTime);
	//}

	if (true == IsPress('Z') && false == IsMove)
	{
		if (true == MoveStack.empty())
		{
			return;
		}
		bool CanGoBack = get<2>(MoveStack.top());		// Ʃ�� �� ��° ����	
		if (false == get<2>(MoveStack.top()))
		{
			return;
		}

		IsMove = true;
		EachInputCheck = true;

		// �̵� : ���� ������ �ݴ�� �̵�
		ReverseMoveSetting(NewInputDir, _DeltaTime);

		// �ִϸ��̼ǿ� �ʿ��� ���� : ���� ������ ������ �ǵ����� ����
		NewInputDir = get<1>(MoveStack.top());		// Ʃ�� �� ��° ����	
		AnimationNumber = get<0>(MoveStack.top());	// Ʃ�� ù ��° ����
		MoveStack.pop();
		return;
	}

	if (true == EachInputCheck)
	{
		MoveStack.push(std::make_tuple(AnimationNumber, CurDir, true));
	}

}

void ALerpMoveObject::InputMove(float _DeltaTime)
{
	if (false == IsMove)
	{
		if (true == IsPress(VK_LEFT))
		{
			AddNextActorLocation(FVector::Left * TileSize);
			NewInputDir = EInputDir::Left;
			IsMove = true;
		}

		if (true == IsPress(VK_RIGHT))
		{
			AddNextActorLocation(FVector::Right * TileSize);
			NewInputDir = EInputDir::Right;
			IsMove = true;
		}

		if (true == IsPress(VK_UP))
		{
			AddNextActorLocation(FVector::Up * TileSize);
			NewInputDir = EInputDir::Up;
			IsMove = true;
		}

		if (true == IsPress(VK_DOWN))
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
				IsMove = false;
				NewInputDir = CurDir;	// �Է� ���� �� �� ��� NewInputDir �ٽ� �ǵ���������
				return;
			}
			// �Է� ���� OK
			EachInputCheck = true;
			LerpStarted = true;
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
		LerpStarted = false;	// �� �� �����ϱ� ����
		LerpTime += _DeltaTime * 3;
		SetActorLocation(LerpCal(LerpTime));
	}
	else
	{
		IsMove = false;
		LerpTime = 0.f;
		SetActorLocation(NextActorLocation);
		CurActorLocation = NextActorLocation;
	}
}

FVector ALerpMoveObject::LerpCal(float _Time)
{
	return CurActorLocation * (1 - _Time) + NextActorLocation * _Time;
}

void ALerpMoveObject::ReverseMoveSetting(EInputDir _Dir, float _DeltaTime)
{
	IsMove = true;
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