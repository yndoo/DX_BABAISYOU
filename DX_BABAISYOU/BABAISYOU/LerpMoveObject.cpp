#include "PreCompile.h"
#include "LerpMoveObject.h"

ALerpMoveObject::ALerpMoveObject()
{
	 InputOn();
}

ALerpMoveObject::~ALerpMoveObject()
{
}


void ALerpMoveObject::Move(float _DeltaTime)
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
			InputCheck = true;
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
		LerpTime += _DeltaTime * 4;
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
		break;
	}
}