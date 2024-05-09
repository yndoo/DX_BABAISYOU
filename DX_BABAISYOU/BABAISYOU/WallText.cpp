#include "PreCompile.h"
#include "WallText.h"

AWallText::AWallText()
{
	Info->TileType = ETileType::Subject;
	Info->MyType = EObjectType::WALLTEXT;
}

AWallText::~AWallText()
{
}

void AWallText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("WALLTEXT_OFF", "WALL.png", AnimationInterVec, { 0, 18, 36 }, true);
	Renderer->CreateAnimation("WALLTEXT_ON", "WALL.png", AnimationInterVec, { 1, 19, 37 }, true);

	AniONOFF();
}

void AWallText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (ON != SentenceON)
	{
		ON = SentenceON;
		AniONOFF();
	}

	int a = 0;
}

void AWallText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("WALLTEXT_ON");
		Info->MyColor = FVector(115, 115, 115);
	}
	else 
	{
		Renderer->ChangeAnimation("WALLTEXT_OFF");
		Info->MyColor = FVector(41, 49, 65);
	}
}