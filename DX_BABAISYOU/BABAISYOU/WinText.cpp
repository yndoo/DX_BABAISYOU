#include "PreCompile.h"
#include "WinText.h"

AWinText::AWinText()
{
	Info->MyType = EObjectType::WIN;
	Info->TileType = ETileType::Objective;
}

AWinText::~AWinText()
{
}

void AWinText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("WIN_White", "WIN.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("WIN_Off", "WIN.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("WIN_On", "WIN.png", AnimationInterVec, { 2, 5, 8 }, true);

	Renderer->ChangeAnimation("WIN_Off");
}

void AWinText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWinText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("WIN_On");
	}
	else
	{
		Renderer->ChangeAnimation("WIN_Off");
	}
}