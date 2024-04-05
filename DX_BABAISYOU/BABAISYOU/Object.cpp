#include "PreCompile.h"
#include "Object.h"

Object::Object()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

Object::~Object()
{
}

void Object::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(400.0f, 400.0f, 100.0f));

	Renderer->SetSprite("Baba_Test.png", 62);
	Renderer->CreateAnimation("BabaTest", "Baba_Test.png", { 1,1,1,1 }, { 1,2,3,4 }, true);
	Renderer->ChangeAnimation("BabaTest");
}

void Object::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}