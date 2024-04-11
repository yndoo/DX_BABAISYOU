#pragma once
#include <EngineCore/SpriteRenderer.h>
#include "PlayerObject.h"

class AStageSelecter : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	AStageSelecter();
	~AStageSelecter();

	AStageSelecter(const AStageSelecter& _Other) = delete;
	AStageSelecter(AStageSelecter&& _Other) noexcept = delete;
	AStageSelecter& operator=(const AStageSelecter& _Other) = delete;
	AStageSelecter& operator=(AStageSelecter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;
private:

};

