#include "PreCompile.h"
#include "GrassText.h"

AGrassText::AGrassText()
{
	Info->MyType = EObjectType::GRASSTEXT;
	Info->TileType = ETileType::Subject;
}

AGrassText::~AGrassText()
{
}

void AGrassText::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("GRASSTEXT_OFF", "GRASS.png", AnimationInterVec, { 0, 18, 36 }, true);
	Renderer->CreateAnimation("GRASSTEXT_ON", "GRASS.png", AnimationInterVec, { 1, 19, 37 }, true);

	AniONOFF();
}

void AGrassText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AGrassText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("GRASSTEXT_On");
	}
	else
	{
		Renderer->ChangeAnimation("GRASSTEXT_Off");
	}
}