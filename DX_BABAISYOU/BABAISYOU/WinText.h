#pragma once
#include "TextObject.h"

class AWinText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AWinText();
	~AWinText();

	AWinText(const AWinText& _Other) = delete;
	AWinText(AWinText&& _Other) noexcept = delete;
	AWinText& operator=(const AWinText& _Other) = delete;
	AWinText& operator=(AWinText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

