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
	EObjectType MyType = EObjectType::NONE;				// ���� ����	
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

	std::map<EObjectType, bool> TextObjective = 		// TEXT ������Ʈ�� �������� �ϼ��� ������. (TEXT�� �����ϸ� �� ��, TEXT�� ��ü�鿡�Ը� ��ȿ�� ��)
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

	void BeginPosSetting();
	Index2D CalPosToIndex(FVector _Pos);
	FVector CalIndexToPos(Index2D _Index);
	Index2D GetMaxIndex();
	bool IndexRangeOverCheck(Index2D Idx);
	void SetMaxIndex();
	void CurToNext(FVector _Cur, FVector _Next);
	bool IsNextPUSH(Index2D _Next);
	virtual bool CanGoNextAll(Index2D _Next, EInputDir _Dir);		// _Dir ������ _Nextĭ�� �� �� �� �ִ��� üũ�ϴ� �Լ�
	void AllPushNextTile(Index2D _Next, EInputDir _Dir);	// _Dir ������ _Nextĭ�� �б�

	void PushTrueHistory();
	void PushFalseHistory();

	ObjectInfo* Info = nullptr;

	FVector CurActorLocation = FVector::Zero;
	bool EachMoveCheck_ForStack = false;		// �̵� �־����� ���ÿ� true��, �������� false�� ���� ���� ����
	bool SentenceON = false;					// ������ ��������� ������ ��.
	bool Destroyed = false;						// �ı������� ON �ž� ��. (���� ���̳� ���Ŀ��� ������. ������ ���������ϴ� ���� X)
	EObjectType DeathType = EObjectType::NONE;	// ���� ����
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool DirCheck();

	UDefaultSceneComponent* Root = nullptr;
	USpriteRenderer* Renderer = nullptr;
	EInputDir CurDir = EInputDir::Right;		// ���� ����
	EInputDir NewInputDir = EInputDir::Right;	// ���� �Է¹޴� �̵� ����
	EInputDir BeforeDir = EInputDir::Right;		// �̵� �� ���� -> ���� ���߿� ������Ʈ�Ǵ� ���� 
	int AnimationNumber = 0;

	// �ѹ� ����� ���� ������ �ʿ���
	std::stack<std::pair<EInputDir, bool>> MoveStack;		// InputDir, IsMove �ൿ ����
	std::stack<std::pair<int, EInputDir>> AnimationStack;	// AnimationNumber, AnimationDir �ִϸ��̼� ����

	// �ٹ��������� ��� ������Ʈ�� 3���� �ִϸ��̼���.
	float AnimationInter = 0.2f;
	std::vector<float> AnimationInterVec = { AnimationInter , AnimationInter , AnimationInter };
private:
	FVector MapScale = FVector::Zero;

};

