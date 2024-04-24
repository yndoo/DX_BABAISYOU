#pragma once
#include "TextObject.h"

class AHotText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AHotText();
	~AHotText();

	AHotText(const AHotText& _Other) = delete;
	AHotText(AHotText&& _Other) noexcept = delete;
	AHotText& operator=(const AHotText& _Other) = delete;
	AHotText& operator=(AHotText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;

private:

};

