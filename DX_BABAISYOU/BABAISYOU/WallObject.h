#pragma once
#include "TileObject.h"

class AWallObject : public ATileObject
{
	GENERATED_BODY(ATileObject)
public:
	AWallObject();
	~AWallObject();

	AWallObject(const AWallObject& _Other) = delete;
	AWallObject(AWallObject&& _Other) noexcept = delete;
	AWallObject& operator=(const AWallObject& _Other) = delete;
	AWallObject& operator=(AWallObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

