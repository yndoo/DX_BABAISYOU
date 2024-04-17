#pragma once
#include "LerpMoveObject.h"

// ���� ������Ʈ��
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
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	bool SentenceON = false; // ������ ��������� ������ ��.
private:

};

