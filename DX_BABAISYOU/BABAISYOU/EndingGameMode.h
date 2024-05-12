#pragma once
#include "BABAGameMode.h"
#include "EngineCore/Image.h"

class EndingGameMode : public BABAGameMode
{
	GENERATED_BODY(AGameMode)
public:
	EndingGameMode();
	~EndingGameMode();

	EndingGameMode(const EndingGameMode& _Other) = delete;
	EndingGameMode(EndingGameMode&& _Other) noexcept = delete;
	EndingGameMode& operator=(const EndingGameMode& _Other) = delete;
	EndingGameMode& operator=(EndingGameMode&& _Other) noexcept = delete;
protected:
	//void BeginPlay() override;
	//void Tick(float _DeltaTime) override;
	//void LevelStart(ULevel* _PrevLevel) override;
	//void LevelEnd(ULevel* _NextLevel) override;

private:

};

