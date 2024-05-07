#include "PreCompile.h"
#include "LavaText.h"

ALavaText::ALavaText()
{
	Info->MyType = EObjectType::LAVATEXT;
	Info->TileType = ETileType::Subject;
}

ALavaText::~ALavaText()
{
}

void ALavaText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("LAVATEXT_OFF", "LAVA.png", AnimationInterVec, { 0, 18, 36 }, true);
	Renderer->CreateAnimation("LAVATEXT_ON", "LAVA.png", AnimationInterVec, { 1, 19, 37 }, true);

	AniONOFF();
}

void ALavaText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (ON != SentenceON)
	{
		ON = SentenceON;
		AniONOFF();
	}

	int a = 0;
}

void ALavaText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("LAVATEXT_ON");
		Info->MyColor = FVector(228, 153, 80);
	}
	else
	{
		Renderer->ChangeAnimation("LAVATEXT_OFF");
		Info->MyColor = FVector(229, 83, 59);
	}
}