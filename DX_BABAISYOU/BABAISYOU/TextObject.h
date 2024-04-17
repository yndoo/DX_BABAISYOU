#pragma once
#include "LerpMoveObject.h"

// ����, �Ӽ�, TEXT ������Ʈ�� �� ��� �ɵ�?
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

