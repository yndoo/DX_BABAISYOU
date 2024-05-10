#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

struct Index2D
{
	int X;
	int Y;

	Index2D operator -(const Index2D _Other)
	{
		Index2D Result = Index2D(0, 0);
		Result.X = X - _Other.X;
		Result.Y = Y - _Other.Y;

		return Result;
	}

	bool operator!=(const Index2D _Other) const
	{
		if (X != _Other.X || Y != _Other.Y)
		{
			return true;
		}
		return false;
	}

	bool operator==(const Index2D _Other) const
	{
		if (X == _Other.X && Y == _Other.Y)
		{
			return true;
		}
		return false;
	}
};

class AObject;
class ObjectInfo
{
public:
	friend AObject;

	ETileType TileType = ETileType::None;
	EObjectType MyType = EObjectType::NONE;				// 내가 뭔지	
	std::map<EObjectType, bool> MyObjectiveType =
	{
		{EObjectType::YOU, false},
		{EObjectType::WIN, false},
		{EObjectType::STOP, false},
		{EObjectType::DEFEAT, false},
		{EObjectType::PUSH, false},
		{EObjectType::FLOAT, false},
		{EObjectType::HOT, false},
		{EObjectType::SINK, false},
		{EObjectType::MELT, false},
	};

	std::map<EObjectType, bool> TextObjective = 		// TEXT 오브젝트와 문장으로 완성된 목적어. (TEXT에 적용하면 안 됨, TEXT인 객체들에게만 유효한 값)
	{
		{EObjectType::YOU, false},
		{EObjectType::WIN, false},
		{EObjectType::STOP, false},
		{EObjectType::DEFEAT, false},
		{EObjectType::PUSH, false},
		{EObjectType::FLOAT, false},
		{EObjectType::HOT, false},
		{EObjectType::SINK, false},
		{EObjectType::MELT, false},
	};

	Index2D CurIndex = Index2D(-1, -1);
	FVector MyColor = FVector::Zero;
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

	void BeginPosSetting();
	Index2D CalPosToIndex(FVector _Pos);
	FVector CalIndexToPos(Index2D _Index);
	Index2D GetMaxIndex();
	bool IndexRangeOverCheck(Index2D Idx);
	void SetMaxIndex();
	void CurToNext(FVector _Cur, FVector _Next);
	bool IsNextPUSH(Index2D _Next);
	virtual bool CanGoNextAll(Index2D _Next, EInputDir _Dir);		// _Dir 방향의 _Next칸에 쭉 갈 수 있는지 체크하는 함수
	void AllPushNextTile(Index2D _Next, EInputDir _Dir);	// _Dir 방향의 _Next칸에 밀기

	void PushTrueHistory();
	void PushFalseHistory();

	ObjectInfo* Info = nullptr;

	FVector CurActorLocation = FVector::Zero;
	bool EachMoveCheck_ForStack = false;		// 이동 있었으면 스택에 true로, 없었으면 false로 들어가기 위한 변수
	bool SentenceON = false;					// 문장이 만들어지면 켜져야 함.
	bool Destroyed = false;						// 파괴됐으면 ON 돼야 함. (눈에 보이냐 마냐에만 관여함. 실제로 지워지게하는 변수 X)
	EObjectType DeathType = EObjectType::NONE;	// 죽은 이유
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool DirCheck();

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* Renderer = nullptr;
	EInputDir CurDir = EInputDir::Right;		// 현재 방향
	EInputDir NewInputDir = EInputDir::Right;	// 새로 입력받는 이동 방향
	EInputDir BeforeDir = EInputDir::Right;		// 이동 전 방향 -> 제일 나중에 업데이트되는 방향 
	int AnimationNumber = 0;

	// 롤백 기능을 위해 스택이 필요함
	std::stack<std::pair<EInputDir, bool>> MoveStack;		// InputDir, IsMove 행동 스택
	std::stack<std::pair<int, EInputDir>> AnimationStack;	// AnimationNumber, AnimationDir 애니메이션 스택

	// 바바이즈유의 모든 오브젝트는 3개씩 애니메이션함.
	float AnimationInter = 0.2f;
	std::vector<float> AnimationInterVec = { AnimationInter , AnimationInter , AnimationInter };
private:
	FVector MapScale = FVector::Zero;

};

