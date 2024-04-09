#pragma once
#include <EngineCore/SpriteRenderer.h>
#include "LerpMoveObject.h"

class AStageSelecter : public ALerpMoveObject
{
	GENERATED_BODY(AActor)
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

