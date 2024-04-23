#include "PreCompile.h"
#include "SkullObject.h"

ASkullObject::ASkullObject()
{
}

ASkullObject::~ASkullObject()
{
}

void ASkullObject::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("SKULL_Right", "SKULL.png", AnimationInterVec, { 0, 4, 8 }, true);
	Renderer->CreateAnimation("SKULL_Up", "SKULL.png", AnimationInterVec, { 1, 5, 9 }, true);
	Renderer->CreateAnimation("SKULL_Left", "SKULL.png", AnimationInterVec, { 2, 6, 10 }, true);
	Renderer->CreateAnimation("SKULL_Down", "SKULL.png", AnimationInterVec, { 3, 7, 11 }, true);

	Renderer->ChangeAnimation("SKULL_Down");
}

void ASkullObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}