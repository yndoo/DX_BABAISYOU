#include "PreCompile.h"
#include "StageSelecter.h"

AStageSelecter::AStageSelecter()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

AStageSelecter::~AStageSelecter()
{
}

void AStageSelecter::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(800.0f, 800.0f, 1.0f));
	Renderer->SetSprite("Selecter.png");
	Renderer->CreateAnimation("Selecter", "Selecter.png", 0.2f);
	Renderer->ChangeAnimation("Selecter");
}

void AStageSelecter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	Move(_DeltaTime);
}