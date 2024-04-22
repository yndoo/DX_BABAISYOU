#include "PreCompile.h"
#include "FlagObject.h"

AFlagObject::AFlagObject()
{
	Info->MyType = EObjectType::FLAG;
}

AFlagObject::~AFlagObject()
{
}

void AFlagObject::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("FLAG_White", "FLAG.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("FLAG_Yellow", "FLAG.png", AnimationInterVec, { 1, 3, 5 }, true);

	Renderer->ChangeAnimation("FLAG_Yellow");
}

void AFlagObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Info;
	int a = 0;
}