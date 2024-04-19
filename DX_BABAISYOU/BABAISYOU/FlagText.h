#pragma once
#include "TextObject.h"

class AFlagText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	AFlagText();
	~AFlagText();

	AFlagText(const AFlagText& _Other) = delete;
	AFlagText(AFlagText&& _Other) noexcept = delete;
	AFlagText& operator=(const AFlagText& _Other) = delete;
	AFlagText& operator=(AFlagText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

