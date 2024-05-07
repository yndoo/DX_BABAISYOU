#include "PreCompile.h"
#include "LavaObject.h"

ALavaObject::ALavaObject()
{
	Info->MyType = EObjectType::LAVA;
	Info->MyColor = FVector(228, 153, 80);
}

ALavaObject::~ALavaObject()
{
}

void ALavaObject::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("LAVA");
	CreateAnimations();
}

void ALavaObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}