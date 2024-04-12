#pragma once
#include <EngineCore/GameMode.h>
#include "MapManager.h"

class AStage1GameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	AStage1GameMode();
	~AStage1GameMode();

	AStage1GameMode(const AStage1GameMode& _Other) = delete;
	AStage1GameMode(AStage1GameMode&& _Other) noexcept = delete;
	AStage1GameMode& operator=(const AStage1GameMode& _Other) = delete;
	AStage1GameMode& operator=(AStage1GameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime);

private:
	void Stage1MapSetting();

	std::shared_ptr<MapManager> MM = nullptr;
};

