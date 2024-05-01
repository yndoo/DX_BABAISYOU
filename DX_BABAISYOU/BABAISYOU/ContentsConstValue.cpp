#include "PreCompile.h"
#include "ContentsConstValue.h"

const FVector UContentsConstValue::StageSelectMapScale = FVector(758, 432);
const FVector UContentsConstValue::StageSelectMapImgScale = FVector(1280.f * 1.5f, 720.f * 1.5f);
const FVector UContentsConstValue::Stage1MapScale = FVector(864, 648);
const FVector UContentsConstValue::Stage3MapScale = FVector(828, 576);
const FVector UContentsConstValue::Stage4MapScale = FVector(864, 504);

const FVector UContentsConstValue::TileScale = FVector(36, 36, 1);
const float UContentsConstValue::TileX = 36.f;
const float UContentsConstValue::TileY = 36.f;
const int UContentsConstValue::ITileX = 36;
const int UContentsConstValue::ITileY = 36;

int UContentsConstValue::MaxIndexX = 0;
int UContentsConstValue::MaxIndexY = 0;
int UContentsConstValue::InputCount = 0;
int UContentsConstValue::ClearStage = 1;
int UContentsConstValue::OpenStageNum = -1;
bool UContentsConstValue::ZInput = false;
bool UContentsConstValue::IsMapEditorUpdated = false;

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