#include "PreCompile.h"
#include "BabaObject.h"

ABabaObject::ABabaObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

ABabaObject::~ABabaObject()
{
}

void ABabaObject::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(400.0f, 400.0f, -100.0f));

	//Renderer->SetSprite("BabaIdle.png", 50);

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

	Renderer->ChangeAnimation("BabaIdle_Right0");
}

void ABabaObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	float Speed = 100.0f;

	if (true == IsPress(VK_LEFT))
	{
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_RIGHT))
	{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_UP))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_DOWN))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}
}