#include "PreCompile.h"
#include "BabaObject.h"

ABabaObject::ABabaObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ABabaObject::~ABabaObject()
{
}

void ABabaObject::CreateBabaAnimations()
{
	int j = 1;
	for (int i = j; i < j + 4; i++)	//BabaIdle_Right0 ~ BabaIdle_Right3
	{
		Renderer->CreateAnimation("BabaIdle_Right" + std::to_string(i - j), "BabaIdle.png", BabaAnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
	j += 4;
	for (int i = j; i < j + 4; i++)	//BabaIdle_Up0 ~ BabaIdle_Up3 
	{
		Renderer->CreateAnimation("BabaIdle_Up" + std::to_string(i - j), "BabaIdle.png", BabaAnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
	j += 4;
	for (int i = j; i < j + 4; i++)	//BabaIdle_Left0 ~ BabaIdle_Left3
	{
		Renderer->CreateAnimation("BabaIdle_Left" + std::to_string(i - j), "BabaIdle.png", BabaAnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
	j += 4;
	for (int i = j; i < j + 4; i++)	//BabaIdle_Down0 ~ BabaIdle_Down3
	{
		Renderer->CreateAnimation("BabaIdle_Down" + std::to_string(i - j), "BabaIdle.png", BabaAnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
}

void ABabaObject::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(400.0f, 400.0f, -100.0f));
	CreateBabaAnimations();

	Renderer->ChangeAnimation("BabaIdle_Right0");
}

void ABabaObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}