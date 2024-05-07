#pragma once
#include "BABAGameMode.h"

#include "StageSelector.h"
#include "StageNumber.h"

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

	void NewStage(int _Num1, int _Num2);
	int IndexToStage(Index2D _index);
private:
	std::shared_ptr<AStageSelector> Selector = nullptr;
	std::vector<std::pair<std::shared_ptr<AStageNumber>, std::shared_ptr<AStageNumber>>> StageNums;

	int CurStage = -1;
	int ClearStage = -1;

	bool MadeStages[8] = { false, };
};

