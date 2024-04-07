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
	SetActorScale3D(FVector(400.0f, 400.0f, -100.0f));

	Renderer->SetSprite("Baba_Test.png", 62);
	//Renderer->CreateAnimation("BabaTest", "Baba_Test.png", 0.1f);
	Renderer->CreateAnimation("BabaTest", "Baba_Test.png", { 1,1,1,1 }, { 59, 60, 61, 62 }, true);
	Renderer->ChangeAnimation("BabaTest");

	// 수업때 쓴 이미지
	//Renderer->SetSprite("CuttingTest.png", 11);
	//Renderer->CreateAnimation("Cutting_Test", "CuttingTest.png", 0.1f);
	//Renderer->ChangeAnimation("Cutting_Test");
}

void Object::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}