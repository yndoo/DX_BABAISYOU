#pragma once
#include <EngineCore/SpriteRenderer.h>
#include "LerpMoveObject.h"

class AMapSelecter : public ALerpMoveObject
{
	GENERATED_BODY(AActor)
public:
	AMapSelecter();
	~AMapSelecter();

	AMapSelecter(const AMapSelecter& _Other) = delete;
	AMapSelecter(AMapSelecter&& _Other) noexcept = delete;
	AMapSelecter& operator=(const AMapSelecter& _Other) = delete;
	AMapSelecter& operator=(AMapSelecter&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;
private:

};

