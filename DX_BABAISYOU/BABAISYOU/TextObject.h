#pragma once
#include "LerpMoveObject.h"

// 동사, 속성, TEXT 오브젝트들 다 묶어도 될듯?
class ATextObject : public ALerpMoveObject
{
	GENERATED_BODY(ALerpMoveObject)
public:
	ATextObject();
	~ATextObject();

	ATextObject(const ATextObject& _Other) = delete;
	ATextObject(ATextObject&& _Other) noexcept = delete;
	ATextObject& operator=(const ATextObject& _Other) = delete;
	ATextObject& operator=(ATextObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

