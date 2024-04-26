#include "PreCompile.h"
#include "FadeInCover.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

AFadeInCover::AFadeInCover()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Renderer->SetOrder(ERenderOrder::Cover);
}

AFadeInCover::~AFadeInCover()
{
}

void AFadeInCover::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("EndCover.png");	
}

void AFadeInCover::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CurScale = GetActorScale3D();
	if (CurScale.X > 1280 * 3 || CurScale.Y > 720 * 3)
	{
		Destroy();
	}

	AddActorScale3D(FVector(1280 * _DeltaTime * 1.5f, 720 * _DeltaTime * 1.5f));

	int a = 0;
}