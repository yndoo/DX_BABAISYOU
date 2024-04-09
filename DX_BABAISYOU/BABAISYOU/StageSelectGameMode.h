#pragma once
#include <EngineCore/GameMode.h>

class AStageSelectGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
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

private:

};

