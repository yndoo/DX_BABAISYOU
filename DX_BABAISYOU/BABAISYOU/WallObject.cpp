#include "PreCompile.h"
#include "WallObject.h"
#include <EngineCore/EngineDebugMsgWindow.h>

AWallObject::AWallObject()
{
	Info->MyType = EObjectType::WALL;
	Info->TileType = ETileType::Player;
}

AWallObject::~AWallObject()
{
}

void AWallObject::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("WALL");
	CreateAnimations();
}

void AWallObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}