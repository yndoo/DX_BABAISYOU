#pragma once
#include <EngineCore/GameMode.h>
#include <EngineBase/EngineDirectory.h>
#include <queue>

#include "Object.h"
#include "MapManager.h"
#include "KeyUIManager.h"

#include "FadeInCover.h"
#include "FadeOUTEffect.h"

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


	void AutoCreate(EObjectType _ObjectType, int _X, int _Y, FVector _MapScale);	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

	virtual void DebugGMM();
	virtual void LoadMapFile(std::string _FileName);
	void Update();
	void StackUpdate();
	void SentenceUpdate();
	void FinalUpdate();
	void DeathCheck();
	void VerbCheck(int _X, int _Y);
	AObject* ObjectiveCheck(int _X, int _Y);
	void ClearAllSentence();

	int SentenceDir = -1;	// 0, 1, 2, 3
	std::queue<AObject*> sentenceQ;
	EGameState GameState = EGameState::SELECTMAP;	// ���� �� SLECETMAP���� ������
	std::shared_ptr<FadeOutEffect> FadeOut;// = nullptr;
	float EffectTime = 3.f;
	FVector CurMapScale = FVector::Zero;

	UEngineDirectory Dir;
	std::vector<int> TileData;	// X, Y, ObjectNum ����.

	std::list<AObject*> AllObjects;		// �ش� ���� ��� ������Ʈ �������. �̰ŷ� Update ����..
	std::list<AObject*> Players;		// ��� Player ������Ʈ�鸸
	std::list<AObject*> Texts;			// ��� TEXT ������Ʈ�鸸
	std::list<AObject*> OnSubjects;		// ���� ON �� �־�� 

	std::shared_ptr<KeyUIManager> UI;
private:
	int BeforeInputCount = 0;

	// Right, Left, Up, Down 
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
};

