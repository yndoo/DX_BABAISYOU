#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// ����������, ��� ������ ���̵��θ� ��
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

