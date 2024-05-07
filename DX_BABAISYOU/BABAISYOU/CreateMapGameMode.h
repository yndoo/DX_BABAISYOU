#pragma once
#include "BABAGameMode.h"

class ACreateMapGameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	ACreateMapGameMode();
	~ACreateMapGameMode();

	ACreateMapGameMode(const ACreateMapGameMode& _Other) = delete;
	ACreateMapGameMode(ACreateMapGameMode&& _Other) noexcept = delete;
	ACreateMapGameMode& operator=(const ACreateMapGameMode& _Other) = delete;
	ACreateMapGameMode& operator=(ACreateMapGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;
private:

};

