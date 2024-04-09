#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

// 플레이어가 될 수 있는 오브젝트들 (ex : BABA, ROCK, ... 의 이미지 오브젝트들)
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

	// 공통된 속성들이 있지 아늘까..
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

