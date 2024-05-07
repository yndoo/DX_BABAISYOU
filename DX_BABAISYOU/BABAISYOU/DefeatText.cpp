#include "PreCompile.h"
#include "DefeatText.h"

ADefeatText::ADefeatText()
{
	Info->MyType = EObjectType::DEFEAT;
	Info->TileType = ETileType::Objective;
}

ADefeatText::~ADefeatText()
{
}

void ADefeatText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("DEFEAT_White", "DEFEAT.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("DEFEAT_Off", "DEFEAT.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("DEFEAT_On", "DEFEAT.png", AnimationInterVec, { 2, 5, 8 }, true);

	AniONOFF();
}

void ADefeatText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ADefeatText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("DEFEAT_On");
		Info->MyColor = FVector(130, 38, 28);
	}
	else
	{
		Renderer->ChangeAnimation("DEFEAT_Off");
		Info->MyColor = FVector(66, 25, 16);
	}
}