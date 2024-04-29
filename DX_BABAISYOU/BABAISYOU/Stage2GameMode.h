#pragma once
#include "BABAGameMode.h"

class AStage2GameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	AStage2GameMode();
	~AStage2GameMode();

	AStage2GameMode(const AStage2GameMode& _Other) = delete;
	AStage2GameMode(AStage2GameMode&& _Other) noexcept = delete;
	AStage2GameMode& operator=(const AStage2GameMode& _Other) = delete;
	AStage2GameMode& operator=(AStage2GameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

private:

};

