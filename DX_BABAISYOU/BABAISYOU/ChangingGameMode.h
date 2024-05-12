#pragma once
#include "BABAGameMode.h"
#include "EngineCore/Image.h"
#include "StageNumber.h"

class AChangingGameMode : public BABAGameMode
{
	GENERATED_BODY(AGameMode)
public:
	AChangingGameMode();
	~AChangingGameMode();

	AChangingGameMode(const AChangingGameMode& _Other) = delete;
	AChangingGameMode(AChangingGameMode&& _Other) noexcept = delete;
	AChangingGameMode& operator=(const AChangingGameMode& _Other) = delete;
	AChangingGameMode& operator=(AChangingGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

	void MakeTitle(int StageNum);
private:
	UImage* Title = nullptr;
	std::shared_ptr<AStageNumber> StageNum2 = nullptr;
	FVector Col = FVector(235, 145, 202);
	FVector TextScale = FVector(54, 54);
	float PassTime = 0.f;
};

