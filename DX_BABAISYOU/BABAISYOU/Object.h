#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

/////////////////////
// 엥???? 2차원 배열 관련은 일단 보류
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

	ETileType TileType = ETileType::None;
	EObjectiveType Objective = EObjectiveType::NONE;

	Index2D CurIdx = Index2D(-1, -1);
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


	void SetMapScale(FVector _Scale)
	{
		MapScale = _Scale;
	}

	Index2D CalPosToIndex(FVector _Pos);
	FVector CalIndexToPos(Index2D _Index);
	Index2D GetMaxIndex();
	bool IndexRangeOverCheck(Index2D Idx);
	void SetMaxIndex();
	void CurToNext(FVector _Cur, FVector _Next);
	bool IsNextPUSH(Index2D _Next);
	bool CanGoNextTile(Index2D _Next, EInputDir _Dir);		// _Dir 방향의 _Next칸에 갈 수 있는지 체크하는 함수
	bool CanGoNextAll(Index2D _Next, EInputDir _Dir);		// _Dir 방향의 _Next칸에 쭉 갈 수 있는지 체크하는 함수
	void AllPushNextTile(Index2D _Next, EInputDir _Dir);	// _Dir 방향의 _Next칸에 밀기

	ObjectInfo* Info = nullptr;
protected:
	void BeginPlay() override;

	USpriteRenderer* Renderer = nullptr;
	UDefaultSceneComponent* Root = nullptr;
private:
	FVector MapScale = FVector::Zero;

};

