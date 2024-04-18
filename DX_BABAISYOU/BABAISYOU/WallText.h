#pragma once
#include "TextObject.h"

class AWallText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AWallText();
	~AWallText();

	AWallText(const AWallText& _Other) = delete;
	AWallText(AWallText&& _Other) noexcept = delete;
	AWallText& operator=(const AWallText& _Other) = delete;
	AWallText& operator=(AWallText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

