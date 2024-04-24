#include "PreCompile.h"
#include "HotText.h"

AHotText::AHotText()
{
	Info->MyType = EObjectType::HOT;
	Info->TileType = ETileType::Objective;
}

AHotText::~AHotText()
{
}

void AHotText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("HOT_White", "HOT.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("HOT_Off", "HOT.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("HOT_On", "HOT.png", AnimationInterVec, { 2, 5, 8 }, true);

	AniONOFF();
}

void AHotText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AHotText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("HOT_On");
	}
	else
	{
		Renderer->ChangeAnimation("HOT_Off");
	}
}