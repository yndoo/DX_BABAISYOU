#pragma once
#include "TextObject.h"

class APushText : public ATextObject
{
	GENERATED_BODY(ATextObject)

public:
	APushText();
	~APushText();

	APushText(const APushText& _Other) = delete;
	APushText(APushText&& _Other) noexcept = delete;
	APushText& operator=(const APushText& _Other) = delete;
	APushText& operator=(APushText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;

private:

};

