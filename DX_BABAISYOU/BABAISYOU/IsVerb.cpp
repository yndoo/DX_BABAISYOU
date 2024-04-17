#include "PreCompile.h"
#include "IsVerb.h"

AIsVerb::AIsVerb()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AIsVerb::~AIsVerb()
{
}

void AIsVerb::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("IS_ON", "IS.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("IS_OFF", "IS.png", AnimationInterVec, { 1, 3, 5 }, true);

	AniONOFF();
}

void AIsVerb::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (ON != SentenceON)
	{
		AniONOFF();
	}
}

void AIsVerb::AniONOFF()
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