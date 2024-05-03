#include "PreCompile.h"
#include "GrassObject.h"

AGrassObject::AGrassObject()
{
	Info->MyType = EObjectType::GRASS;
	Info->TileType = ETileType::Player;
}

AGrassObject::~AGrassObject()
{
}

void AGrassObject::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("GRASS");
	CreateAnimations();
}

void AGrassObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}