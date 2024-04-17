#pragma once
#include "TextObject.h"

class AIsText : public ATextObject
{
	GENERATED_BODY(ATextObject)

public:
	AIsText();
	~AIsText();

	AIsText(const AIsText& _Other) = delete;
	AIsText(AIsText&& _Other) noexcept = delete;
	AIsText& operator=(const AIsText& _Other) = delete;
	AIsText& operator=(AIsText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void AniONOFF();
private:
	bool ON = false;
};

