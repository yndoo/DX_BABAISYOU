#pragma once
#include "ContentsEnum.h"

 // 컨텐츠 영역에서 전역으로 사용할 변수들
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
	static bool ZInput;			//전역 Z Input 체크
	static bool IsMapEditorUpdated;

	static std::map<EObjectType, EObjectType> TextToPlayer;
};

