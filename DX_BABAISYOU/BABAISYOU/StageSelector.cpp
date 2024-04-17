#include "PreCompile.h"
#include "StageSelector.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

AStageSelector::AStageSelector()
{
	InputOn();
}

AStageSelector::~AStageSelector()
{
}

void AStageSelector::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(36, 36, 1));

	Renderer->SetSprite("Selector.png");
	Renderer->CreateAnimation("Selector", "Selector.png", 0.2f);
	Renderer->ChangeAnimation("Selector");
	bool Test = Renderer->IsActive();
}

void AStageSelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	{
		std::string Msg = std::format("SelecterPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("SelecterScale : {}\n", GetActorScale3D().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	if (true == EachInputCheck)
	{
		// Super���� ���� ������ ���⼭ false�� �ٲ���.
		// Selector�� InputCheck �ʿ� ����.
		EachInputCheck = false;	
	}
}