#pragma once
#include "BABAGameMode.h"
#include "EngineCore/Image.h"

class AEndingGameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	AEndingGameMode();
	~AEndingGameMode();

	AEndingGameMode(const AEndingGameMode& _Other) = delete;
	AEndingGameMode(AEndingGameMode&& _Other) noexcept = delete;
	AEndingGameMode& operator=(const AEndingGameMode& _Other) = delete;
	AEndingGameMode& operator=(AEndingGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	//void LevelEnd(ULevel* _NextLevel) override;

private:

};

