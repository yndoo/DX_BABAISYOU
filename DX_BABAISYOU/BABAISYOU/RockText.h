#pragma once
#include "TextObject.h"

class ARockText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	ARockText();
	~ARockText();

	ARockText(const ARockText& _Other) = delete;
	ARockText(ARockText&& _Other) noexcept = delete;
	ARockText& operator=(const ARockText& _Other) = delete;
	ARockText& operator=(ARockText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

