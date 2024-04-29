#pragma once
#include "PlayerObject.h"

class ABackTileObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	ABackTileObject();
	~ABackTileObject();

	ABackTileObject(const ABackTileObject& _Other) = delete;
	ABackTileObject(ABackTileObject&& _Other) noexcept = delete;
	ABackTileObject& operator=(const ABackTileObject& _Other) = delete;
	ABackTileObject& operator=(ABackTileObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
private:

};

