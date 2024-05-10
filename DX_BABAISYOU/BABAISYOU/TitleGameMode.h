#pragma once
#include "BABAGameMode.h"
#include "EngineCore/Image.h"

class ATitleGameMode : public BABAGameMode
{
	GENERATED_BODY(AGameMode)
public:
	ATitleGameMode();
	~ATitleGameMode();

	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	//void LevelEnd(ULevel* _NextLevel) override;

	UImage* StartBtn = nullptr;
	UImage* ExitBtn = nullptr;
	UImage* Cursor = nullptr;
private:

};

