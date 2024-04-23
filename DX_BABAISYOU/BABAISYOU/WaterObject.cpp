#include "PreCompile.h"
#include "WaterObject.h"

AWaterObject::AWaterObject()
{
	Info->MyType = EObjectType::WATER;
}

AWaterObject::~AWaterObject()
{
}

void AWaterObject::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("WATER");
	CreateAnimations();
}

void AWaterObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
