#pragma once
#include <EngineCore/GameMode.h>
#include <EngineBase/EngineDirectory.h>
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
	AObject* VerbCheck(int _X, int _Y);
	AObject* ObjectiveCheck(int _X, int _Y);
	void ClearAllSentence();
	int SentenceDir = -1;	// 0, 1, 2, 3

	UEngineDirectory Dir;
	std::vector<int> TileData;	// X, Y, ObjectNum 순서.

	std::list<AObject*> AllObjects;		// 해당 레벨 모든 오브젝트 들고있음. 이거로 Update 하자..
	std::list<AObject*> Players;		// 모든 Player 오브젝트들만
	std::list<AObject*> Texts;			// 모든 TEXT 오브젝트들만
	std::list<AObject*> OnSubjects;		// 문장 ON 된 주어들 
private:
	int BeforeInputCount = 0;

	// Right, Left, Up, Down 
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
};

