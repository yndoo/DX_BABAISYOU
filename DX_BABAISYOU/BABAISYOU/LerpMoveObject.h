#pragma once
#include "Object.h"
#include "ContentsEnum.h"

// 입력에 의해 Lerp 이동하는 기능, (예정 : 밀려서 Lerp 이동하는 기능도 할 수 있어야 함)
class ALerpMoveObject : public AObject
{
	GENERATED_BODY(AObject)
public:
	ALerpMoveObject();
	~ALerpMoveObject();

	ALerpMoveObject(const ALerpMoveObject& _Other) = delete;
	ALerpMoveObject(ALerpMoveObject&& _Other) noexcept = delete;
	ALerpMoveObject& operator=(const ALerpMoveObject& _Other) = delete;
	ALerpMoveObject& operator=(ALerpMoveObject&& _Other) noexcept = delete;

	void SetIsMove(bool _IsMove) 
	{
		IsMove = _IsMove;
	}

	void SetCurDir(EInputDir _Dir)
	{
		CurDir = _Dir;
	}

	void AddNextActorLocation(FVector _Add);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void Update(float _DeltaTime);

	void InputMove(float _DeltaTime);
	void ReverseMoveSetting(EInputDir _Dir, float _DeltaTime, bool _CanMove);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);

	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;					// 1920*1080 환경에서는 한 타일 54*54
	bool IsMove = false;					// 움직이는 "중"인지 나타내는 변수
	bool EachInputCheck = false;			// 이동 Input이 있었으면 애니메이션을 갱신 (각 Object 단위)
	bool ZInputCheck = false;				// Z Input이 있었으면 애니메이션 넘기지 말기.
	
private:
};