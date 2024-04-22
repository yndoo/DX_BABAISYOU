#include "PreCompile.h"
#include "FlagText.h"

AFlagText::AFlagText()
{
	Info->TileType = ETileType::Subject;
	Info->MyType = EObjectType::FLAGTEXT;
}

AFlagText::~AFlagText()
{
}

void AFlagText::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("FLAGTEXT_White", "FLAGText.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("FLAGTEXT_Off", "FLAGText.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("FLAGTEXT_On", "FLAGText.png", AnimationInterVec, { 2, 5, 8 }, true);

	AniONOFF();
}

void AFlagText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AFlagText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("FLAGTEXT_On");
	}
	else
	{
		Renderer->ChangeAnimation("FLAGTEXT_Off");
	}
}