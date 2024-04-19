#pragma once
#include "PlayerObject.h"

class AFlagObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	AFlagObject();
	~AFlagObject();

	AFlagObject(const AFlagObject& _Other) = delete;
	AFlagObject(AFlagObject&& _Other) noexcept = delete;
	AFlagObject& operator=(const AFlagObject& _Other) = delete;
	AFlagObject& operator=(AFlagObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

};

