#pragma once
#include "BABAGameMode.h"
#include "Background.h"

class AStageGameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	AStageGameMode();
	~AStageGameMode();

	AStageGameMode(const AStageGameMode& _Other) = delete;
	AStageGameMode(AStageGameMode&& _Other) noexcept = delete;
	AStageGameMode& operator=(const AStageGameMode& _Other) = delete;
	AStageGameMode& operator=(AStageGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

private:
	std::shared_ptr<ABackground> Back;
};

