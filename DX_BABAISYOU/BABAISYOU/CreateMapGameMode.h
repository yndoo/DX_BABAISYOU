#pragma once
#include <EngineCore/GameMode.h>

class CreateMapGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
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

private:

};

