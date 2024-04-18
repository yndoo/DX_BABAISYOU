#include "PreCompile.h"
#include "StopText.h"

AStopText::AStopText()
{
	Info->MyType = EObjectType::STOP;
	Info->TileType = ETileType::Objective;
}

AStopText::~AStopText()
{
}

void AStopText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("STOP_White", "STOP.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("STOP_Off", "STOP.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("STOP_On", "STOP.png", AnimationInterVec, { 2, 5, 8 }, true);
							   
	Renderer->ChangeAnimation("STOP_Off");
}

void AStopText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}