#pragma once
#include "LerpMoveObject.h"

class AVerbObject : public ALerpMoveObject
{
	GENERATED_BODY(ALerpMoveObject)
public:
	AVerbObject();
	~AVerbObject();

	AVerbObject(const AVerbObject& _Other) = delete;
	AVerbObject(AVerbObject&& _Other) noexcept = delete;
	AVerbObject& operator=(const AVerbObject& _Other) = delete;
	AVerbObject& operator=(AVerbObject&& _Other) noexcept = delete;
protected:

private:

};

