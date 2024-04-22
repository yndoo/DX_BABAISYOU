#include "PreCompile.h"
#include "SinkText.h"

ASinkText::ASinkText()
{
	Info->MyType = EObjectType::SINK;
	Info->TileType = ETileType::Objective;
}

ASinkText::~ASinkText()
{
}

void ASinkText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("SINK_White", "SINK.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("SINK_Off", "SINK.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("SINK_On", "SINK.png", AnimationInterVec, { 2, 5, 8 }, true);

	AniONOFF();
}

void ASinkText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ASinkText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("SINK_On");
	}
	else
	{
		Renderer->ChangeAnimation("SINK_Off");
	}
}