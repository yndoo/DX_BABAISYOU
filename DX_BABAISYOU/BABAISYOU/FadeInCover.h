#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// 덮개같은애, 얘는 무조건 페이드인만 함
class AFadeInCover : public AActor
{
	GENERATED_BODY(AActor)
public:
	AFadeInCover();
	~AFadeInCover();

	AFadeInCover(const AFadeInCover& _Other) = delete;
	AFadeInCover(AFadeInCover&& _Other) noexcept = delete;
	AFadeInCover& operator=(const AFadeInCover& _Other) = delete;
	AFadeInCover& operator=(AFadeInCover&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

private:
};

