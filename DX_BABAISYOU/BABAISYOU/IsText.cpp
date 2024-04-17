#include "PreCompile.h"
#include "IsText.h"

AIsText::AIsText()
{
	Info->TileType = ETileType::Verb;
	Info->MyType = EObjectType::IS;
}

AIsText::~AIsText()
{
}

void AIsText::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("IS_ON", "IS.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("IS_OFF", "IS.png", AnimationInterVec, { 1, 3, 5 }, true);

	AniONOFF();
}

void AIsText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (ON != SentenceON)
	{
		ON = SentenceON;
		AniONOFF();
	}
}

void AIsText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("IS_ON");
	}
	else
	{
		Renderer->ChangeAnimation("IS_OFF");
	}
}