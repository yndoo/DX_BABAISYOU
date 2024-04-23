#pragma once
#include "PlayerObject.h"

class ASkullObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	ASkullObject();
	~ASkullObject();

	ASkullObject(const ASkullObject& _Other) = delete;
	ASkullObject(ASkullObject&& _Other) noexcept = delete;
	ASkullObject& operator=(const ASkullObject& _Other) = delete;
	ASkullObject& operator=(ASkullObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

