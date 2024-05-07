#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

class TextActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	TextActor();
	~TextActor();

	TextActor(const TextActor& _Other) = delete;
	TextActor(TextActor&& _Other) noexcept = delete;
	TextActor& operator=(const TextActor& _Other) = delete;
	TextActor& operator=(TextActor&& _Other) noexcept = delete;

	void SetAnimation(std::string_view _Alpha);
	void SetRendererScale(FVector _Scale);
	void SetRendererMulColor(FVector _Color);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* Renderer = nullptr;

	void CreateAlphaAnimation();
private:
	float AnimationInter = 0.2f;
	std::vector<float> AnimationInterVec = { AnimationInter , AnimationInter , AnimationInter };
};

