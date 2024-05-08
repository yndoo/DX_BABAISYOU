#include "PreCompile.h"
#include "Bridge.h"
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

ABridge::ABridge()
{
	InputOff();
	Info->MyType = EObjectType::LINE;
}

ABridge::~ABridge()
{
}

void ABridge::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("LINE");
	CreateAnimations();
}

void ABridge::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}