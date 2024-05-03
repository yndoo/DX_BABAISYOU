#pragma once
#include "TextObject.h"

class AGrassText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AGrassText();
	~AGrassText();

	AGrassText(const AGrassText& _Other) = delete;
	AGrassText(AGrassText&& _Other) noexcept = delete;
	AGrassText& operator=(const AGrassText& _Other) = delete;
	AGrassText& operator=(AGrassText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;

private:

};

