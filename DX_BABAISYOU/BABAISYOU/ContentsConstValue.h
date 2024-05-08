#pragma once
#include "ContentsEnum.h"

 // ������ �������� �������� ����� ������
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
	static int ClearStage;		// ���� �������� ��ȣ
	static int OpenStageNum;	// �����ؾ� �ϴ� �������� ��ȣ
	static bool ZInput;			// ���� Z Input üũ

	static std::map<EObjectType, EObjectType> TextToPlayer;
};

