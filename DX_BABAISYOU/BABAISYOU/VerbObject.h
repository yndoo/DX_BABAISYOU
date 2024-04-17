#pragma once
#include "LerpMoveObject.h"

// 동사 오브젝트들
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

	bool SentenceON = false; // 문장이 만들어지면 켜져야 함.
private:

};

