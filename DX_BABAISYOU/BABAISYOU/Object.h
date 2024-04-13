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

class AObject;
class ObjectInfo
{
public:
	friend AObject;
	EObjectType ObjType = EObjectType::None;
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

	Index2D CalPosToIndex(FVector _Pos);
	FVector CalIndexToPos(Index2D _Index);
	Index2D GetMaxIndex();
	void SetMaxIndex();
protected:
	void BeginPlay() override;

	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;

	ObjectInfo* Info = nullptr;
private:
	FVector MapScale = FVector::Zero;

};

