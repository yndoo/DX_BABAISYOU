#include "PreCompile.h"
#include "YouText.h"

AYouText::AYouText()
{
	Info->MyType = EObjectType::YOU;
}

AYouText::~AYouText()
{
}

void AYouText::BeginPlay()
{
	Super::BeginPlay();
	Renderer->CreateAnimation("YOU_White", "YOU.png", AnimationInterVec, { 0, 3, 6 }, true);
	Renderer->CreateAnimation("YOU_Purple", "YOU.png", AnimationInterVec, { 1, 4, 7 }, true);
	Renderer->CreateAnimation("YOU_Pink", "YOU.png", AnimationInterVec, { 2, 5, 8 }, true);

	Renderer->ChangeAnimation("YOU_Pink");
}

void AYouText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}