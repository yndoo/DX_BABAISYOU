#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class URenderer;
class ATestObject : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATestObject();
	~ATestObject();

	// delete Function
	ATestObject(const ATestObject& _Other) = delete;
	ATestObject(ATestObject&& _Other) noexcept = delete;
	ATestObject& operator=(const ATestObject& _Other) = delete;
	ATestObject& operator=(ATestObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	URenderer* Renderer;
};

