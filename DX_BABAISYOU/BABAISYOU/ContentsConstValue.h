#pragma once
#include "ContentsEnum.h"

 // ������ �������� �������� ����� ������
class UContentsConstValue
{
public:
	static const FVector StageSelectMapScale;
	static const FVector StageSelectMapImgScale;
	static const FVector Stage1MapScale;

	static const FVector TileScale;
	static const float TileX;
	static const float TileY;
	static const int ITileX;
	static const int ITileY;

	static int MaxIndexX;
	static int MaxIndexY;
	static int InputCount;

	static std::map<EObjectType, EObjectType> TextToPlayer;
};

