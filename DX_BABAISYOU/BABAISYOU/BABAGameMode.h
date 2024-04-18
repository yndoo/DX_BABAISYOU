#pragma once
#include <EngineCore/GameMode.h>
#include "MapManager.h"
#include "Object.h"

class BABAGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	BABAGameMode();
	~BABAGameMode();

	BABAGameMode(const BABAGameMode& _Other) = delete;
	BABAGameMode(BABAGameMode&& _Other) noexcept = delete;
	BABAGameMode& operator=(const BABAGameMode& _Other) = delete;
	BABAGameMode& operator=(BABAGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	//void LevelStart(ULevel* _PrevLevel) override;

	virtual void DebugGMM();
	void Update();
	void StackUpdate();
	void SentenceUpdate();
	void FinalUpdate();
	AObject* VerbCheck(int _X, int _Y);
	AObject* ObjectiveCheck(int _X, int _Y);
	void ClearAllSentence();
	int SentenceDir = -1;	// 0, 1, 2, 3

	std::list<AObject*> AllObjects;		// �ش� ���� ��� ������Ʈ �������. �̰ŷ� Update ����..
	std::list<AObject*> Players;		// ��� Player ������Ʈ�鸸
	std::list<AObject*> Texts;			// ��� TEXT ������Ʈ�鸸
	std::list<AObject*> OnSubjects;		// ���� ON �� �־�� 
private:
	int BeforeInputCount = 0;

	// Right, Left, Up, Down 
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
};

