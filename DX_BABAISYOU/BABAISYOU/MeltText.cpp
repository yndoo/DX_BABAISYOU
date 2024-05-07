#include "PreCompile.h"
#include "MeltText.h"

AMeltText::AMeltText()
{
	Info->MyType = EObjectType::MELT;
	Info->TileType = ETileType::Objective;
	Info->MyColor = FVector(95, 157, 209);
}

AMeltText::~AMeltText()
{
}

void AMeltText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("MELT_White", "MELT.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("MELT_Off", "MELT.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("MELT_On", "MELT.png", AnimationInterVec, { 2, 5, 8 }, true);

	AniONOFF();
}

void AMeltText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AMeltText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("MELT_On");
		Info->MyColor = FVector(95, 157, 209);
	}
	else
	{
		Renderer->ChangeAnimation("MELT_Off");
		Info->MyColor = FVector(62, 118, 136);
	}
}