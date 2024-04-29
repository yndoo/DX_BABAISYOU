#include "PreCompile.h"
#include "StageSelector.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

AStageSelector::AStageSelector()
{
	InputOn();
	Info->MyObjectiveType[EObjectType::YOU] = true;
}

AStageSelector::~AStageSelector()
{
}

void AStageSelector::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Selector.png");
	Renderer->CreateAnimation("Selector", "Selector.png", 0.2f);
	Renderer->ChangeAnimation("Selector");
}

void AStageSelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}