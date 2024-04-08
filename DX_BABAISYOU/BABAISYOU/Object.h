#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class Object : public AActor
{
	GENERATED_BODY(AActor)
public:
	Object();
	~Object();

	Object(const Object& _Other) = delete;
	Object(Object&& _Other) noexcept = delete;
	Object& operator=(const Object& _Other) = delete;
	Object& operator=(Object&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

	// ����� �Ӽ����� ���� �ƴñ�.,,.
	float AnimationInter = 0.2f;
	std::vector<float> BabaAnimationInterVec = { AnimationInter , AnimationInter , AnimationInter };
private:
	
};

