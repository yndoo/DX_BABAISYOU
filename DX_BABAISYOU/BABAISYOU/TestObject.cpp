#include "PreCompile.h"
#include "TestObject.h"
#include <EngineCore/Renderer.h>

ATestObject::ATestObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ATestObject::~ATestObject()
{
}

void ATestObject::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(700.0f, 700.0f, 100.0f));

	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->SetSprite("CuttingTest.png", 11);

	Renderer->CreateAnimation("Run", "CuttingTest.png", 0.1f);

	Renderer->ChangeAnimation("Run");
}

void ATestObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	float Speed = 100.0f;

	if (true == UEngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}


	if (true == UEngineInput::IsPress(VK_NUMPAD1))
	{
		Color.X += _DeltaTime;
	}

	if (true == UEngineInput::IsPress(VK_NUMPAD2))
	{
		Color.X -= _DeltaTime;
	}

	if (true == UEngineInput::IsPress(VK_NUMPAD4))
	{
		Color.Y += _DeltaTime;
	}

	if (true == UEngineInput::IsPress(VK_NUMPAD5))
	{
		Color.Y -= _DeltaTime;
	}

	if (true == UEngineInput::IsPress(VK_NUMPAD7))
	{
		Color.Z += _DeltaTime;
	}

	if (true == UEngineInput::IsPress(VK_NUMPAD8))
	{
		Color.Z -= _DeltaTime;
	}

}