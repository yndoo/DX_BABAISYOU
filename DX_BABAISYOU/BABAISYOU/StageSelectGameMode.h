#pragma once
#include "BABAGameMode.h"

class AStageSelectGameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	AStageSelectGameMode();
	~AStageSelectGameMode();

	AStageSelectGameMode(const AStageSelectGameMode& _Other) = delete;
	AStageSelectGameMode(AStageSelectGameMode&& _Other) noexcept = delete;
	AStageSelectGameMode& operator=(const AStageSelectGameMode& _Other) = delete;
	AStageSelectGameMode& operator=(AStageSelectGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime);
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

private:

};

