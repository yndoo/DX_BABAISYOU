#pragma once
#include "VerbObject.h"

class AIsVerb : public AVerbObject
{
	GENERATED_BODY(AVerbObject)

public:
	AIsVerb();
	~AIsVerb();

	AIsVerb(const AIsVerb& _Other) = delete;
	AIsVerb(AIsVerb&& _Other) noexcept = delete;
	AIsVerb& operator=(const AIsVerb& _Other) = delete;
	AIsVerb& operator=(AIsVerb&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void AniONOFF();
private:
	bool ON = false;
};

