#include "PreCompile.h"
#include "WaterObject.h"

AWaterObject::AWaterObject()
{
	Info->MyType = EObjectType::WATER;
	Info->TileType = ETileType::Tile;
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
