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
	//void Update(float _DeltaTime);

	std::shared_ptr<MapManager> MM = nullptr;
	std::list<AObject*> AllObjects;	// 해당 레벨 모든 오브젝트 들고있음. 이거로 Update 하자..
private:
	int BeforeInputCount = 0;
};

