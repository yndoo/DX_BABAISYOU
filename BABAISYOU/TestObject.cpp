#include "PreCompile.h"
#include "TestObject.h"
#include <EngineCore/Renderer.h>

ATestObject::ATestObject()
{
	Renderer = CreateDefaultSubObject<URenderer>("Renderer");
	Renderer->SetMesh("Rect");

	Renderer->SetMaterial("2DImage");

}

ATestObject::~ATestObject()
{
}

void ATestObject::BeginPlay()
{
	Super::BeginPlay();


	ULevel* Test = GetWorld();

	SetActorScale3D(FVector(100.0f, 100.0f, 100.0f));
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
}