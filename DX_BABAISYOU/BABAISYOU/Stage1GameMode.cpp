#include "PreCompile.h"
#include <EngineCore/Camera.h>
#include <EngineCore/EngineDebugMsgWindow.h>

#include "Stage1GameMode.h"
#include "MapManager.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"

#include "Background.h"

#include "BabaObject.h"
#include "WallObject.h"
#include "FlagObject.h"

#include "IsText.h"
#include "BabaText.h"
#include "YouText.h"
#include "WallText.h"
#include "StopText.h"
#include "FlagText.h"
#include "WinText.h"


AStage1GameMode::AStage1GameMode()
{
}

AStage1GameMode::~AStage1GameMode()
{
}

void AStage1GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DebugGMM();
}

void AStage1GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);
	

	LoadMapFile("Stage1");

	Update();
}

void AStage1GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AStage1GameMode::Stage1MapSetting(FVector MapScale)
{
	GMapManager->ClearGraph();

	/* ============= Player Object들 ============= */
	AutoCreate(EObjectType::BABA, 13, 8, MapScale);
	
	AutoCreate(EObjectType::WALL, 1, 1, MapScale);
	AutoCreate(EObjectType::WALL, 1, 2, MapScale);
	AutoCreate(EObjectType::WALL, 1, 3, MapScale);
	AutoCreate(EObjectType::WALL, 3, 3, MapScale);

	AutoCreate(EObjectType::WATER, 14, 4, MapScale);
	AutoCreate(EObjectType::WATER, 15, 5, MapScale);
	AutoCreate(EObjectType::WATER, 16, 6, MapScale);

	AutoCreate(EObjectType::LAVA, 15, 3, MapScale);
	AutoCreate(EObjectType::LAVA, 15, 4, MapScale);
	AutoCreate(EObjectType::LAVA, 15, 5, MapScale);

	AutoCreate(EObjectType::GRASS, 15, 15, MapScale);

	AutoCreate(EObjectType::FLAG, 8, 5, MapScale);
	AutoCreate(EObjectType::ROCK, 6, 11, MapScale);
	AutoCreate(EObjectType::SKULL, 7, 11, MapScale);

	/* ============= 주어 Object들 ============= */
	AutoCreate(EObjectType::BABATEXT, 10, 4, MapScale);
	AutoCreate(EObjectType::WALLTEXT, 9, 3, MapScale);
	AutoCreate(EObjectType::FLAGTEXT, 9, 4, MapScale);
	AutoCreate(EObjectType::WATERTEXT, 13, 7, MapScale);
	AutoCreate(EObjectType::ROCKTEXT, 3, 11, MapScale);
	AutoCreate(EObjectType::SKULLTEXT, 0, 0, MapScale);
	AutoCreate(EObjectType::LAVATEXT, 4, 2, MapScale);

	/* ============= 동사 Object들 ============= */
	AutoCreate(EObjectType::IS, 10, 3, MapScale);
	AutoCreate(EObjectType::IS, 4, 10, MapScale);
	AutoCreate(EObjectType::IS, 1, 0, MapScale);
	AutoCreate(EObjectType::IS, 5, 1, MapScale);
	
	/* ============= 목적어 Object들 ============= */
	AutoCreate(EObjectType::YOU, 10, 2, MapScale);
	AutoCreate(EObjectType::STOP, 12, 2, MapScale);
	AutoCreate(EObjectType::WIN, 13, 2, MapScale);
	AutoCreate(EObjectType::DEFEAT, 2, 0, MapScale);
	AutoCreate(EObjectType::PUSH, 5, 11, MapScale);
	AutoCreate(EObjectType::SINK, 15, 7, MapScale);
	AutoCreate(EObjectType::HOT, 6, 1, MapScale);
}

void AStage1GameMode::DebugGMM()
{
	for (int y = 19; y >= 0; y--)		// 세로
	{
		std::string Msg = "";
		for (int x = 0; x < 24; x++)	// 가로
		{
			int ss = GMapManager->Graph[x][y].size();

			Msg += std::format("{} ", std::to_string(ss));
		}
		Msg += "\n";
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}