#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// �÷��̾ �� �� �ִ� ������Ʈ�� (ex : BABA, ROCK, ... �� �̹��� ������Ʈ��)
class APlayerObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	APlayerObject();
	~APlayerObject();

	APlayerObject(const APlayerObject& _Other) = delete;
	APlayerObject(APlayerObject&& _Other) noexcept = delete;
	APlayerObject& operator=(const APlayerObject& _Other) = delete;
	APlayerObject& operator=(APlayerObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

	// ����� �Ӽ����� ���� �ƴñ�..
	float AnimationInter = 0.2f;
	std::vector<float> BabaAnimationInterVec = { AnimationInter , AnimationInter , AnimationInter };
private:
	void AddNextActorLocation(FVector _Add);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);
	
	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;
	bool IsMove = false;
};

