#include "PreCompile.h"
#include "StageSelecter.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

AStageSelecter::AStageSelecter()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	InputOn();
}

AStageSelecter::~AStageSelecter()
{
}

void AStageSelecter::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(36, 36, 1));

	Renderer->SetSprite("Selecter.png");
	Renderer->CreateAnimation("Selecter", "Selecter.png", 0.2f);
	Renderer->ChangeAnimation("Selecter");
	bool Test = Renderer->IsActive();
}

void AStageSelecter::Tick(float _DeltaTime)
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
		// Super먼저 돌기 때문에 여기서 false로 바꿔줌.
		// Selecter는 InputCheck 필요 없음.
		EachInputCheck = false;	
	}
}