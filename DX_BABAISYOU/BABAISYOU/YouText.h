#pragma once
#include "TextObject.h"

class AYouText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AYouText();
	~AYouText();

	AYouText(const AYouText& _Other) = delete;
	AYouText(AYouText&& _Other) noexcept = delete;
	AYouText& operator=(const AYouText& _Other) = delete;
	AYouText& operator=(AYouText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

