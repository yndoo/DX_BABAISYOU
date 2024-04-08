#pragma once
#include <EngineCore/GameMode.h>

class ASelectMapGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	ASelectMapGameMode();
	~ASelectMapGameMode();

	ASelectMapGameMode(const ASelectMapGameMode& _Other) = delete;
	ASelectMapGameMode(ASelectMapGameMode&& _Other) noexcept = delete;
	ASelectMapGameMode& operator=(const ASelectMapGameMode& _Other) = delete;
	ASelectMapGameMode& operator=(ASelectMapGameMode&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime);

private:

};

