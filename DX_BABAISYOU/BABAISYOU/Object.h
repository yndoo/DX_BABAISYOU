#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"

/////////////////////
// 엥???? 2차원 배열 관련은 일단 보류
/////////////////////

struct Index2D
{
	int X;
	int Y;
};

// 맵에 표시되는 모든 오브젝트
class AObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	AObject();
	~AObject();

	AObject(const AObject& _Other) = delete;
	AObject(AObject&& _Other) noexcept = delete;
	AObject& operator=(const AObject& _Other) = delete;
	AObject& operator=(AObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;

	Index2D PosToIndex(FVector _Pos);
private:
	FVector WinScale = FVector::Zero;

};

