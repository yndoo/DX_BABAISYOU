#include "PreCompile.h"
#include "FootPrint.h"
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

AFootPrint::AFootPrint()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Renderer->SetOrder(ERenderOrder::Player);
}

AFootPrint::~AFootPrint()
{
}

void AFootPrint::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("FootPrint.png");
	SetActorScale3D(FVector(24, 24));
}

void AFootPrint::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector Scale = GetActorScale3D();
	if (Scale.X > 5)
	{
		Scale = Scale + FVector((-50.f) * _DeltaTime, (-50.f) * _DeltaTime);
		SetActorScale3D(Scale);
		//AddActorScale3D(FVector((-50.f) * _DeltaTime, (-50.f) * _DeltaTime));
	}
	else
	{
		Destroy();
		//SetActive(false);
	}
}