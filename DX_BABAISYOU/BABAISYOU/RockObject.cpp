#include "PreCompile.h"
#include "RockObject.h"

ARockObject::ARockObject()
{
	Info->MyType = EObjectType::ROCK;
}

ARockObject::~ARockObject()
{
}
void ARockObject::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Rock", "ROCK.png", AnimationInterVec, { 0, 1, 2 }, true);
	Renderer->ChangeAnimation("Rock");
}

void ARockObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}