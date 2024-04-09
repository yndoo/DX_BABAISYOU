#pragma once
#include "PlayerObject.h"

class ABabaObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	ABabaObject();
	~ABabaObject();

	ABabaObject(const ABabaObject& _Other) = delete;
	ABabaObject(ABabaObject&& _Other) noexcept = delete;
	ABabaObject& operator=(const ABabaObject& _Other) = delete;
	ABabaObject& operator=(ABabaObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void CreateBabaAnimations();
};

