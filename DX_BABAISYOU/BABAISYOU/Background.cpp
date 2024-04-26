#include "PreCompile.h"
#include "Background.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

ABackground::ABackground()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Renderer->SetOrder(ERenderOrder::Background);
}

ABackground::~ABackground()
{
}

void ABackground::BeginPlay()
{
	Super::BeginPlay();
}

void ABackground::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	{
		/*std::string Msg = std::format("MapPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);*/
	}
}

void ABackground::SelectStageSetting()
{
	Renderer->SetSprite("SelectMap_background.png", 2);
	Renderer->CreateAnimation("Back", "SelectMap_background.png", 0.2f);
	Renderer->ChangeAnimation("Back");
}

void ABackground::Stage1Setting()
{
  	Renderer->SetSprite("Back_One.png");
}