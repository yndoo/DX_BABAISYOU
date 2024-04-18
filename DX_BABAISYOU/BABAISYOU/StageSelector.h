#pragma once
#include <EngineCore/SpriteRenderer.h>
#include "PlayerObject.h"

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

private:

};
