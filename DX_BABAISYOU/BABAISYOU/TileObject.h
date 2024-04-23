#pragma once
#include "PlayerObject.h"

// 붙어있는 부분과 아닌 부분의 이미지가 달라져야 하는 타일 오브젝트들 묶음 (ex : Water, Lava, ...)
class ATileObject : public APlayerObject
{
	GENERATED_BODY(APlayerObject)
public:
	ATileObject();
	~ATileObject();

	ATileObject(const ATileObject& _Other) = delete;
	ATileObject(ATileObject&& _Other) noexcept = delete;
	ATileObject& operator=(const ATileObject& _Other) = delete;
	ATileObject& operator=(ATileObject&& _Other) noexcept = delete;

	void SetTileNum(int _num)
	{
		TileNum = _num;
	}

	void SetTileName(std::string_view _name)
	{
		TileName = _name;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void TileDirUpdate();
	void CreateAnimations();


	std::string TileName = "";
	int TileNum = 0;
	int CurTileNum = -1;

private:
	int MyPow(int _Num, int _Pow);
};

