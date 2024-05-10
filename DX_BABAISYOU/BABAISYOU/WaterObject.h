#pragma once
#include "TileObject.h"
class AWaterObject : public ATileObject
{
	GENERATED_BODY(ATileObject)
public:
	AWaterObject();
	~AWaterObject();

	AWaterObject(const AWaterObject& _Other) = delete;
	AWaterObject(AWaterObject&& _Other) noexcept = delete;
	AWaterObject& operator=(const AWaterObject& _Other) = delete;
	AWaterObject& operator=(AWaterObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	bool MyLife = false;

};

