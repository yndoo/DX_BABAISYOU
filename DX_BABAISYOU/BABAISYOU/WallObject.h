#pragma once
#include "PlayerObject.h"

class AWallObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	AWallObject();
	~AWallObject();

	AWallObject(const AWallObject& _Other) = delete;
	AWallObject(AWallObject&& _Other) noexcept = delete;
	AWallObject& operator=(const AWallObject& _Other) = delete;
	AWallObject& operator=(AWallObject&& _Other) noexcept = delete;
protected:

private:

};

