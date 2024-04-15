#pragma once
#include "Object.h"
#include "ContentsEnum.h"
#include <stack>
#include <tuple>

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
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void InputMove(float _DeltaTime);
	void ReverseMoveSetting(EInputDir _Dir, float _DeltaTime);
	void AddNextActorLocation(FVector _Add);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);

	EInputDir NewInputDir = EInputDir::Right;	
	EInputDir CurDir = EInputDir::Right;
	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;		// 1920*1080 환경에서는 한 타일 54*54
	bool IsMove = false;		// 움직이는 중인지 나타내는 변수
	bool LerpStarted = false;	// IsMove인 객체 중에 움직임을 시작하는 순간을 나타내기 위한 변수..
	//static int SomeMoveCnt;		// 움직이는 LerpMoveObject 개수 변수
	//static int SomeStayCnt;		// 멈춰있는 LerpMoveObject 개수 변수
	//static int CurLerpObjCnt;	// 현재 LerpMoveObject 개수 변수
	//bool IsReverseMove = false;	
	bool EachInputCheck = false;	// Input이 있었으면 애니메이션을 갱신 (각 Object 단위)
	int AnimationNumber = 0;
	//되돌려질 스택이 필요함
	std::stack<std::tuple <int, EInputDir, bool >> MoveStack;	// AnimationNumber, InputDir, IsMove
private:
};