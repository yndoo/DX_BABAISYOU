#pragma once
#include "TextObject.h"

class ALavaText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	ALavaText();
	~ALavaText();

	ALavaText(const ALavaText& _Other) = delete;
	ALavaText(ALavaText&& _Other) noexcept = delete;
	ALavaText& operator=(const ALavaText& _Other) = delete;
	ALavaText& operator=(ALavaText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

