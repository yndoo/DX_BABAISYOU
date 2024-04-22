#pragma once
#include "PlayerObject.h"
class ARockObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	ARockObject();
	~ARockObject();

	ARockObject(const ARockObject& _Other) = delete;
	ARockObject(ARockObject&& _Other) noexcept = delete;
	ARockObject& operator=(const ARockObject& _Other) = delete;
	ARockObject& operator=(ARockObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

