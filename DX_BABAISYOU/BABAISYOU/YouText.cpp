#include "PreCompile.h"
#include "YouText.h"

AYouText::AYouText()
{
	Info->MyType = EObjectType::YOU;
	Info->TileType = ETileType::Objective;
}

AYouText::~AYouText()
{
}

void AYouText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("YOU_White", "YOU.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("YOU_Off", "YOU.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("YOU_On", "YOU.png", AnimationInterVec, { 2, 5, 8 }, true);

	Renderer->ChangeAnimation("YOU_Off");
}

void AYouText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AYouText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("YOU_On");
		Info->MyColor = FVector(217, 57, 106);
	}
	else
	{
		Renderer->ChangeAnimation("YOU_Off");
		Info->MyColor = FVector(104, 46, 76);
	}
}