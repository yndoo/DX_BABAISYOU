#pragma once

#include "MapManager.h"
#include "BABAGameMode.h"

// 맨 처음 했던 방식
class AStage1GameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	AStage1GameMode();
	~AStage1GameMode();

	AStage1GameMode(const AStage1GameMode& _Other) = delete;
	AStage1GameMode(AStage1GameMode&& _Other) noexcept = delete;
	AStage1GameMode& operator=(const AStage1GameMode& _Other) = delete;
	AStage1GameMode& operator=(AStage1GameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void DebugGMM() override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

private:
	void Stage1MapSetting(FVector MapScale);

};

