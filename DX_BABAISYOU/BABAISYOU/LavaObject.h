#pragma once
#include "TileObject.h"

class ALavaObject : public ATileObject
{
	GENERATED_BODY(ATileObject)
public:
	ALavaObject();
	~ALavaObject();

	ALavaObject(const ALavaObject& _Other) = delete;
	ALavaObject(ALavaObject&& _Other) noexcept = delete;
	ALavaObject& operator=(const ALavaObject& _Other) = delete;
	ALavaObject& operator=(ALavaObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

