#pragma once
#include "TextObject.h"

class ABabaText : public ATextObject
{
	GENERATED_BODY(ATextObject)
public:
	ABabaText();
	~ABabaText();

	ABabaText(const ABabaText& _Other) = delete;
	ABabaText(ABabaText&& _Other) noexcept = delete;
	ABabaText& operator=(const ABabaText& _Other) = delete;
	ABabaText& operator=(ABabaText&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void AniONOFF() override;
private:
	EObjectType CurObjType = EObjectType::NONE;
};

