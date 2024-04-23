#include "PreCompile.h"
#include "WallObject.h"
#include <EngineCore/EngineDebugMsgWindow.h>

AWallObject::AWallObject()
{
	Info->MyType = EObjectType::WALL;
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