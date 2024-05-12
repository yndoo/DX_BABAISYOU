#include "PreCompile.h"
#include "ContentsConstValue.h"

const FVector UContentsConstValue::StageSelectMapScale = FVector(758, 576);	// 21 X 16?
//const FVector UContentsConstValue::StageSelectMapScale = FVector(758, 432);	// 21 X 12?
const FVector UContentsConstValue::StageSelectMapImgScale = FVector(1280.f * 1.5f, 720.f * 1.5f);
const FVector UContentsConstValue::Stage0MapScale = FVector(1188, 648);	// 33 X 18
const FVector UContentsConstValue::Stage1MapScale = FVector(864, 648);	// 24 X 18
const FVector UContentsConstValue::Stage3MapScale = FVector(828, 576);
const FVector UContentsConstValue::Stage4MapScale = FVector(864, 504);	// 24 X 14
const FVector UContentsConstValue::Stage5MapScale = FVector(1188, 648);	// 33 X 18
const FVector UContentsConstValue::Stage8MapScale = FVector(1080, 576);	// 15 X 8 (�� ĭ�� 72)

const FVector UContentsConstValue::TileScale = FVector(36, 36, 1);
const float UContentsConstValue::TileX = 36.f;
const float UContentsConstValue::TileY = 36.f;
int UContentsConstValue::ITileX = 36;
int UContentsConstValue::ITileY = 36;

bool UContentsConstValue::StageCleared[10] = { false, };
bool UContentsConstValue::MadeStages[10] = { false, };

int UContentsConstValue::MaxIndexX = 0;
int UContentsConstValue::MaxIndexY = 0;
int UContentsConstValue::InputCount = 0;
int UContentsConstValue::ClearStage = 0;
int UContentsConstValue::OpenStageNum = -1;
bool UContentsConstValue::ZInput = false;

std::map<EObjectType, EObjectType> UContentsConstValue::TextToPlayer = {
	{EObjectType::BABATEXT, EObjectType::BABA},
	{EObjectType::WALLTEXT, EObjectType::WALL},
	{EObjectType::FLAGTEXT, EObjectType::FLAG},
	{EObjectType::WATERTEXT, EObjectType::WATER},
	{EObjectType::ROCKTEXT, EObjectType::ROCK},
	{EObjectType::LAVATEXT, EObjectType::LAVA},
	{EObjectType::GRASSTEXT, EObjectType::GRASS},
	{EObjectType::SKULLTEXT, EObjectType::SKULL},
};