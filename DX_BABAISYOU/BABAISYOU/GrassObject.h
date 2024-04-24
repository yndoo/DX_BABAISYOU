#pragma once
#include "TileObject.h"

class AGrassObject : public ATileObject
{
	GENERATED_BODY(ATileObject)
public:
	AGrassObject();
	~AGrassObject();

	AGrassObject(const AGrassObject& _Other) = delete;
	AGrassObject(AGrassObject&& _Other) noexcept = delete;
	AGrassObject& operator=(const AGrassObject& _Other) = delete;
	AGrassObject& operator=(AGrassObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

