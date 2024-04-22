#pragma once
#include "PlayerObject.h"
class AWaterObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	AWaterObject();
	~AWaterObject();

	AWaterObject(const AWaterObject& _Other) = delete;
	AWaterObject(AWaterObject&& _Other) noexcept = delete;
	AWaterObject& operator=(const AWaterObject& _Other) = delete;
	AWaterObject& operator=(AWaterObject&& _Other) noexcept = delete;

	void SetTileNum(int _num)
	{
		TileNum = _num;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	void CreateWaterAnimations();
	int TileNum = 0;
	int CurTileNum = 0;
};

