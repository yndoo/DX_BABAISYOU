#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

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


	void SetMapScale(FVector _Scale)
	{
		MapScale = _Scale;
	}

protected:
	void BeginPlay() override;

	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;

	Index2D PosToIndex(FVector _Pos);
	FVector IndexToPos(Index2D _Index);
private:
	FVector MapScale = FVector::Zero;

};

