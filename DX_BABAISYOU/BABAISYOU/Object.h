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

	// 공통된 속성들이 있지 아늘까.,,.
private:
	USpriteRenderer* Renderer;
};

