#pragma once
#include "BABAGameMode.h"

class CreateMapGameMode : public BABAGameMode
{
	GENERATED_BODY(BABAGameMode)
public:
	CreateMapGameMode();
	~CreateMapGameMode();

	CreateMapGameMode(const CreateMapGameMode& _Other) = delete;
	CreateMapGameMode(CreateMapGameMode&& _Other) noexcept = delete;
	CreateMapGameMode& operator=(const CreateMapGameMode& _Other) = delete;
	CreateMapGameMode& operator=(CreateMapGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;
private:

};

