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

	virtual void DebugGMM();
	void StackUpdate();
	void SentenceUpdate();
	AObject* VerbCheck(int _X, int _Y);
	AObject* ObjectiveCheck(int _X, int _Y);
	int SentenceDir = -1;	// 0, 1, 2, 3

	std::list<AObject*> AllObjects;	// 해당 레벨 모든 오브젝트 들고있음. 이거로 Update 하자..
private:
	int BeforeInputCount = 0;

	// Right, Left, Up, Down 
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
};

