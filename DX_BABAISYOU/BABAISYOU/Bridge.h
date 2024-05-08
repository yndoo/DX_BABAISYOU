#pragma once
#include "TileObject.h"

class ABridge : public ATileObject
{
	GENERATED_BODY(ATileObject)
public:
	ABridge();
	~ABridge();

	ABridge(const ABridge& _Other) = delete;
	ABridge(ABridge&& _Other) noexcept = delete;
	ABridge& operator=(const ABridge& _Other) = delete;
	ABridge& operator=(ABridge&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

