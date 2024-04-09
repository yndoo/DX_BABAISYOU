#pragma once
#include <EngineCore/Actor.h>

enum class EInputDir
{
	None,
	Right,
	Left,
	Up,
	Down,
};

// 입력받아 이동하는 기능
class ALerpMoveObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	ALerpMoveObject();
	~ALerpMoveObject();

	ALerpMoveObject(const ALerpMoveObject& _Other) = delete;
	ALerpMoveObject(ALerpMoveObject&& _Other) noexcept = delete;
	ALerpMoveObject& operator=(const ALerpMoveObject& _Other) = delete;
	ALerpMoveObject& operator=(ALerpMoveObject&& _Other) noexcept = delete;
protected:
	void Move(float _DeltaTime);
	void AddNextActorLocation(FVector _Add);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);

	EInputDir NewInputDir = EInputDir::Right;
	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;		// 1920*1080 환경에서는 한 타일 54*54
	bool IsMove = false;
	bool InputCheck = false;
private:
};

