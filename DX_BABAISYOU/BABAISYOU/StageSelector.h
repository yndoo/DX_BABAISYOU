#pragma once
#include "PlayerObject.h"
#include "EngineCore/Image.h"

class AStageSelector : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	AStageSelector();
	~AStageSelector();

	AStageSelector(const AStageSelector& _Other) = delete;
	AStageSelector(AStageSelector&& _Other) noexcept = delete;
	AStageSelector& operator=(const AStageSelector& _Other) = delete;
	AStageSelector& operator=(AStageSelector&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool CanGoNextAll(Index2D _Next, EInputDir _Dir) override;

	void MakeTitle(int StageNum);
private:
	int IndexToStage(Index2D _index);
	int MyCurStageNum = -1;
	UImage* Title = nullptr;
};

