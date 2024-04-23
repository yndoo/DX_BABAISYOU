#pragma once
#include "TextObject.h"

class ASkullText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	ASkullText();
	~ASkullText();

	ASkullText(const ASkullText& _Other) = delete;
	ASkullText(ASkullText&& _Other) noexcept = delete;
	ASkullText& operator=(const ASkullText& _Other) = delete;
	ASkullText& operator=(ASkullText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

