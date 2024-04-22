#include "PreCompile.h"
#include "PushText.h"

APushText::APushText()
{
	Info->MyType = EObjectType::PUSH;
	Info->TileType = ETileType::Objective;
}

APushText::~APushText()
{
}


void APushText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("PUSH_White", "PUSH.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("PUSH_Off", "PUSH.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("PUSH_On", "PUSH.png", AnimationInterVec, { 2, 5, 8 }, true);

	AniONOFF();
}

void APushText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void APushText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("PUSH_On");
	}
	else
	{
		Renderer->ChangeAnimation("PUSH_Off");
	}
}