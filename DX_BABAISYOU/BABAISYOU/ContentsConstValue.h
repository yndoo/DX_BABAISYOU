#pragma once
#include "ContentsEnum.h"

 // ������ �������� �������� ����� ������
class UContentsConstValue
{
public:
	static const FVector StageSelectMapScale;
	static const FVector StageSelectMapImgScale;
	static const FVector Stage1MapScale;
	static const FVector Stage3MapScale;
	static const FVector Stage4MapScale;

	static const FVector TileScale;
	static const float TileX;
	static const float TileY;
	static const int ITileX;
	static const int ITileY;

	static int MaxIndexX;
	static int MaxIndexY;
	static int InputCount;
	static int ClearStage;		// ���� �������� ��ȣ
	static int OpenStageNum;	// �����ؾ� �ϴ� �������� ��ȣ
	static bool ZInput;			// ���� Z Input üũ
	static bool IsMapEditorUpdated;

	static std::map<EObjectType, EObjectType> TextToPlayer;
};

