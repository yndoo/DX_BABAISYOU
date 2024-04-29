#pragma once
#include "PlayerObject.h"

// 숫자 액터
class AStageNumber : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	AStageNumber();
	~AStageNumber();

	AStageNumber(const AStageNumber& _Other) = delete;
	AStageNumber(AStageNumber&& _Other) noexcept = delete;
	AStageNumber& operator=(const AStageNumber& _Other) = delete;
	AStageNumber& operator=(AStageNumber&& _Other) noexcept = delete;

	void SetStageNum(int _Num)
	{
		StageNum = _Num;
		Renderer->ChangeAnimation(std::to_string(StageNum) + "_White");
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

	void CreateNumAni();
private:
	int StageNum = -1;
};

