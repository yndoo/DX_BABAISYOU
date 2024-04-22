#include "PreCompile.h"
#include <EngineCore/Camera.h>
#include <EngineCore/EngineDebugMsgWindow.h>

#include "Stage1GameMode.h"
#include "Background.h"
#include "MapManager.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"

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
	Stage1MapSetting(UContentsConstValue::Stage1MapScale);	// 맵 오브젝트 세팅하는 곳


	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -200.0f));

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);
	Update();
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DebugGMM();
}

void AStage1GameMode::Stage1MapSetting(FVector MapScale)
{
	/* ============= Player Object들 ============= */
	AutoCreate(EObjectType::BABA, 13, 8, MapScale);
	
	AutoCreate(EObjectType::WALL, 1, 1, MapScale, 0);
	AutoCreate(EObjectType::WALL, 2, 2, MapScale, 1);
	AutoCreate(EObjectType::WALL, 3, 3, MapScale, 15);

	AutoCreate(EObjectType::WATER, 14, 4, MapScale, 0);
	AutoCreate(EObjectType::WATER, 15, 5, MapScale, 1);
	AutoCreate(EObjectType::WATER, 16, 6, MapScale, 15);

	AutoCreate(EObjectType::FLAG, 8, 5, MapScale);
	AutoCreate(EObjectType::ROCK, 6, 11, MapScale);

	/* ============= 주어 Object들 ============= */
	AutoCreate(EObjectType::BABATEXT, 10, 4, MapScale);
	AutoCreate(EObjectType::WALLTEXT, 9, 3, MapScale);
	AutoCreate(EObjectType::FLAGTEXT, 9, 4, MapScale);
	AutoCreate(EObjectType::WATERTEXT, 13, 7, MapScale);
	AutoCreate(EObjectType::ROCKTEXT, 3, 11, MapScale);

	/* ============= 동사 Object들 ============= */
	AutoCreate(EObjectType::IS, 10, 3, MapScale);
	AutoCreate(EObjectType::IS, 4, 10, MapScale);
	
	/* ============= 목적어 Object들 ============= */
	AutoCreate(EObjectType::YOU, 10, 2, MapScale);
	AutoCreate(EObjectType::STOP, 12, 2, MapScale);
	AutoCreate(EObjectType::WIN, 13, 2, MapScale);
	AutoCreate(EObjectType::DEFEAT, 11, 5, MapScale);
	AutoCreate(EObjectType::PUSH, 5, 11, MapScale);
	AutoCreate(EObjectType::SINK, 15, 7, MapScale);
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