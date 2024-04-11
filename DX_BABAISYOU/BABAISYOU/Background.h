#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ABackground : public AActor
{
	GENERATED_BODY(AActor)
public:
	ABackground();
	~ABackground();

	ABackground(const ABackground& _Other) = delete;
	ABackground(ABackground&& _Other) noexcept = delete;
	ABackground& operator=(const ABackground& _Other) = delete;
	ABackground& operator=(ABackground&& _Other) noexcept = delete;

	void SelectStageSetting();
	void Stage1Setting();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

private:

};

