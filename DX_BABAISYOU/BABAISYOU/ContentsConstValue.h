#pragma once
#include "ContentsEnum.h"

 // 컨텐츠 영역에서 전역으로 사용할 변수들
class UContentsConstValue
{
public:
	static const FVector StageSelectMapScale;
	static const FVector StageSelectMapImgScale;
	static const FVector Stage0MapScale;
	static const FVector Stage1MapScale;
	static const FVector Stage3MapScale;
	static const FVector Stage4MapScale;
	static const FVector Stage5MapScale;

	static const FVector TileScale;
	static const float TileX;
	static const float TileY;
	static const int ITileX;
	static const int ITileY;

	static bool StageCleared[10];
	static int MaxIndexX;
	static int MaxIndexY;
	static int InputCount;
	static int ClearStage;		// 다음 스테이지 번호
	static int OpenStageNum;	// 입장해야 하는 스테이지 번호
	static bool ZInput;			// 전역 Z Input 체크

	static std::map<EObjectType, EObjectType> TextToPlayer;
};

