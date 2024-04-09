#include "PreCompile.h"
#include "MapSelecter.h"

AMapSelecter::AMapSelecter()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//InputOn(); 부모에서 해줌
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
	
	Move(_DeltaTime);
}