#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"

/////////////////////
// ��???? 2���� �迭 ������ �ϴ� ����
/////////////////////

struct Index2D
{
	int X;
	int Y;
};

// �ʿ� ǥ�õǴ� ��� ������Ʈ
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

