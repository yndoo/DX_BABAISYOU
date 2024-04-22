#include "PreCompile.h"
#include "RockText.h"

ARockText::ARockText()
{
	Info->MyType = EObjectType::ROCKTEXT;
	Info->TileType = ETileType::Subject;
}

ARockText::~ARockText()
{
}

void ARockText::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("ROCKTEXT_Off", "ROCKText.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("ROCKTEXT_On", "ROCKText.png", AnimationInterVec, { 1, 3, 5 }, true);

	AniONOFF();
}

void ARockText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ARockText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("ROCKTEXT_On");
	}
	else
	{
		Renderer->ChangeAnimation("ROCKTEXT_Off");
	}
}