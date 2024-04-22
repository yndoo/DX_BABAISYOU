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
	Stage1MapSetting(UContentsConstValue::Stage1MapScale);	// �� ������Ʈ �����ϴ� ��


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
	/* ============= Player Object�� ============= */
	AutoCreate(EObjectType::BABA, 8, 4, MapScale);
	
	AutoCreate(EObjectType::WALL, 1, 1, MapScale, 0);
	AutoCreate(EObjectType::WALL, 2, 2, MapScale, 1);
	AutoCreate(EObjectType::WALL, 3, 3, MapScale, 15);

	AutoCreate(EObjectType::WATER, 11, 11, MapScale, 0);
	AutoCreate(EObjectType::WATER, 12, 12, MapScale, 1);
	AutoCreate(EObjectType::WATER, 13, 13, MapScale, 15);

	AutoCreate(EObjectType::FLAG, 8, 5, MapScale);

	/* ============= �־� Object�� ============= */
	AutoCreate(EObjectType::BABATEXT, 10, 4, MapScale);
	AutoCreate(EObjectType::WALLTEXT, 12, 4, MapScale);
	AutoCreate(EObjectType::FLAGTEXT, 9, 4, MapScale);
	AutoCreate(EObjectType::WATERTEXT, 9, 9, MapScale);

	/* ============= ���� Object�� ============= */
	AutoCreate(EObjectType::IS, 10, 3, MapScale);
	
	/* ============= ������ Object�� ============= */
	AutoCreate(EObjectType::YOU, 10, 2, MapScale);
	AutoCreate(EObjectType::STOP, 12, 2, MapScale);
	AutoCreate(EObjectType::WIN, 13, 2, MapScale);
	AutoCreate(EObjectType::DEFEAT, 11, 5, MapScale);
	AutoCreate(EObjectType::PUSH, 11, 6, MapScale);
	AutoCreate(EObjectType::SINK, 7, 5, MapScale);
}

void AStage1GameMode::DebugGMM()
{
	for (int y = 19; y >= 0; y--)		// ����
	{
		std::string Msg = "";
		for (int x = 0; x < 24; x++)	// ����
		{
			int ss = GMapManager->Graph[x][y].size();

			Msg += std::format("{} ", std::to_string(ss));
		}
		Msg += "\n";
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}