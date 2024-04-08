#include "PreCompile.h"
#include "MapSelecter.h"

AMapSelecter::AMapSelecter()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//InputOn();
}

AMapSelecter::~AMapSelecter()
{
}

void AMapSelecter::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(800.0f, 800.0f, 1.0f));
	Renderer->SetSprite("Selecter.png");
	Renderer->CreateAnimation("Selecter", "Selecter.png", 0.2f);
	Renderer->ChangeAnimation("Selecter");
}

void AMapSelecter::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AddActorRotation(FVector{ 0.f,0.f,0.f,0.1f });
	int b = 0;
}