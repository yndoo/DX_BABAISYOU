#pragma once
#include "TextObject.h"

class ASinkText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	ASinkText();
	~ASinkText();

	ASinkText(const ASinkText& _Other) = delete;
	ASinkText(ASinkText&& _Other) noexcept = delete;
	ASinkText& operator=(const ASinkText& _Other) = delete;
	ASinkText& operator=(ASinkText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

