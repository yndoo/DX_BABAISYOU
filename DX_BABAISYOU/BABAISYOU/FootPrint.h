#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AFootPrint : public AActor
{
	GENERATED_BODY(AActor)
public:
	AFootPrint();
	~AFootPrint();

	AFootPrint(const AFootPrint& _Other) = delete;
	AFootPrint(AFootPrint&& _Other) noexcept = delete;
	AFootPrint& operator=(const AFootPrint& _Other) = delete;
	AFootPrint& operator=(AFootPrint&& _Other) noexcept = delete;

	void SetRendererMulColor(FVector _Color);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

private:

};

