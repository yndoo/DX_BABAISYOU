#include "PreCompile.h"
#include "WaterText.h"

AWaterText::AWaterText()
{
	Info->MyType = EObjectType::WATERTEXT;
	Info->TileType = ETileType::Subject;
}

AWaterText::~AWaterText()
{
}

void AWaterText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("WATERTEXT_OFF", "WATER.png", AnimationInterVec, { 0, 18, 36 }, true);
	Renderer->CreateAnimation("WATERTEXT_ON", "WATER.png", AnimationInterVec, { 1, 19, 37 }, true);

	AniONOFF();
}

void AWaterText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (ON != SentenceON)
	{
		ON = SentenceON;
		AniONOFF();
	}

	int a = 0;
}

void AWaterText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("WATERTEXT_ON");
	}
	else
	{
		Renderer->ChangeAnimation("WATERTEXT_OFF");
	}
}