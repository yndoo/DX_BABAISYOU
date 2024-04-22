#pragma once
#include "TextObject.h"

class AWaterText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AWaterText();
	~AWaterText();

	AWaterText(const AWaterText& _Other) = delete;
	AWaterText(AWaterText&& _Other) noexcept = delete;
	AWaterText& operator=(const AWaterText& _Other) = delete;
	AWaterText& operator=(AWaterText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

