#pragma once
#include "TextObject.h"

class ADefeatText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	ADefeatText();
	~ADefeatText();

	ADefeatText(const ADefeatText& _Other) = delete;
	ADefeatText(ADefeatText&& _Other) noexcept = delete;
	ADefeatText& operator=(const ADefeatText& _Other) = delete;
	ADefeatText& operator=(ADefeatText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:

};

