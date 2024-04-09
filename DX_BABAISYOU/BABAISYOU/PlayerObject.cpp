#include "PreCompile.h"
#include "PlayerObject.h"

APlayerObject::APlayerObject()
{
	InputOn();
}

APlayerObject::~APlayerObject()
{
}

void APlayerObject::BeginPlay()
{
	Super::BeginPlay();
	CurActorLocation = GetActorLocation();
}

void APlayerObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsPress(VK_LEFT))
	{
		AddNextActorLocation(FVector::Left * TileSize);
		IsMove = true;
	}

	if (true == IsPress(VK_RIGHT))
	{
		AddNextActorLocation(FVector::Right * TileSize);
		IsMove = true;
	}

	if (true == IsPress(VK_UP))
	{
		AddNextActorLocation(FVector::Up * TileSize);
		IsMove = true;
	}

	if (true == IsPress(VK_DOWN))
	{
		AddNextActorLocation(FVector::Down * TileSize);
		IsMove = true;
	}

	LerpMove(_DeltaTime);
}

void APlayerObject::AddNextActorLocation(FVector _Add)
{
	NextActorLocation = GetActorLocation() + _Add;
}

void APlayerObject::LerpMove(float _DeltaTime)
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

FVector APlayerObject::LerpCal(float _Time)
{
	return CurActorLocation * (1 - _Time) + NextActorLocation * _Time;
}