#pragma once
#include "EngineCore/Actor.h"
#include "EngineCore/Image.h"

#include "TextActor.h"

class KeyUIManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	KeyUIManager();
	~KeyUIManager();

	KeyUIManager(const KeyUIManager& _Other) = delete;
	KeyUIManager(KeyUIManager&& _Other) noexcept = delete;
	KeyUIManager& operator=(const KeyUIManager& _Other) = delete;
	KeyUIManager& operator=(KeyUIManager&& _Other) noexcept = delete;

	void KeyUIOff();
	void KeyUIOn();

	bool GetCurOn()
	{
		return CurOn;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CreateUI();
	UImage* UndoKey = nullptr;
	UImage* RestartKey = nullptr;
	bool CurOn = true;

	std::vector<TextActor*> TextActors;
};

