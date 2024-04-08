#include "PreCompile.h"
#include "Background.h"
#include <EngineCore/EngineCore.h>

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

	SetActorScale3D(FVector(1024.0f, 1024.0f, 1.0f));
	FVector Test = GEngine->EngineWindow.GetWindowScale();
	//FVector(1280.0f, 720.0f, 100.0f)
	Renderer->SetSprite("SelectMap_background.png", 2);
	Renderer->CreateAnimation("Back", "SelectMap_background.png", 0.2f);
	Renderer->ChangeAnimation("Back");
}

void ABackground::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}