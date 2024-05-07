#pragma once
#include <EngineCore/GameMode.h>

class ATitleGameMode : public AGameMode
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

private:

};

