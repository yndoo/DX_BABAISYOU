#include "PreCompile.h"
#include "Background.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/EngineDebugMsgWindow.h>

ABackground::ABackground()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ABackground::~ABackground()
{
}

void ABackground::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(1280.0f * 1.3f, 720.0f * 2.45f, 1.0f));
	//SetActorScale3D(FVector(1280.0f * 1.3f * 0.9f, 720.0f * 2.45f * 0.8f, 1.0f));
	//FVector Test = GEngine->EngineWindow.GetWindowScale();
	//FVector(1280.0f, 720.0f, 100.0f)

}

void ABackground::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	{
		std::string Msg = std::format("MapPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
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
	// ╬Й╢б ©жема╝
	//Renderer->SetSprite("testmap_back_mini.png");
 	Renderer->SetSprite("testmap_back.png");
}