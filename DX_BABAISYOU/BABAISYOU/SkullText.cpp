#include "PreCompile.h"
#include "SkullText.h"

ASkullText::ASkullText()
{
	Info->MyType = EObjectType::SKULLTEXT;
	Info->TileType = ETileType::Subject;
}

ASkullText::~ASkullText()
{
}

void ASkullText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("SKULLTEXT_OFF", "SKULLText.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("SKULLTEXT_ON", "SKULLText.png", AnimationInterVec, { 1, 3, 5 }, true);

	AniONOFF();
}

void ASkullText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (ON != SentenceON)
	{
		ON = SentenceON;
		AniONOFF();
	}

	int a = 0;
}

void ASkullText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("SKULLTEXT_ON");
	}
	else
	{
		Renderer->ChangeAnimation("SKULLTEXT_OFF");
	}
}