#pragma once
#include "Object.h"
#include "ContentsEnum.h"
#include <stack>

// 입력에 의해 Lerp 이동하는 기능
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
protected:
	void BeginPlay() override;

	void Move(float _DeltaTime);
	void ReverseMoveSetting(EInputDir _Dir, float _DeltaTime);
	void AddNextActorLocation(FVector _Add);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);

	EInputDir NewInputDir = EInputDir::Right;
	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;		// 1920*1080 환경에서는 한 타일 54*54
	bool IsMove = false;		// 움직이는 중인지 나타내는 변수
	//bool IsReverseMove = false;	
	bool InputCheck = false;	// Input이 있었으면 애니메이션을 갱신
	int AnimationNumber = 0;
	std::stack<std::pair<int, EInputDir>> MoveStack;	//되돌려질 스택이 필요함
private:
};

