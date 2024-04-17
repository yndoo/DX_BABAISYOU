#include "PreCompile.h"
#include "Stage1GameMode.h"
#include <EngineCore/Camera.h>
#include "BabaObject.h"
#include "MapManager.h"
#include "WallObject.h"
#include "Background.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"
#include <EngineCore/EngineDebugMsgWindow.h>


AStage1GameMode::AStage1GameMode()
{
}

AStage1GameMode::~AStage1GameMode()
{
}

void AStage1GameMode::BeginPlay()
{
	Super::BeginPlay();
	Stage1MapSetting();	// 맵 오브젝트 세팅하는 곳

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -200.0f));

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DebugGMM();
}

void AStage1GameMode::Stage1MapSetting()
{
	std::shared_ptr<ABabaObject> Baba = GetWorld()->SpawnActor<ABabaObject>("Baba");
	// 얘네는 같은 게임모드인 모든 Object 같이 세팅해야하는 것들
	Baba->SetMapScale(UContentsConstValue::Stage1MapScale);
	Baba->SetMaxIndex();
	Baba->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로

	Baba->AddActorLocation(Baba->CalIndexToPos(Index2D(0, 0)));
	Baba->BeginPosSetting();
	Baba->SetOrder(ERenderOrder::FrontTile);
	Baba->Info->Objective = EObjectiveType::YOU;
	AllObjects.push_back(Baba.get());


	std::shared_ptr<ABabaObject> Baba2 = GetWorld()->SpawnActor<ABabaObject>("Baba");
	// 얘네는 같은 게임모드인 모든 Object 같이 세팅해야하는 것들
	Baba2->SetMapScale(UContentsConstValue::Stage1MapScale);
	Baba2->SetMaxIndex();
	Baba2->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로

	Baba2->AddActorLocation(Baba2->CalIndexToPos(Index2D(1, 0)));
	Baba2->BeginPosSetting();
	Baba2->SetOrder(ERenderOrder::FrontTile);
	Baba2->Info->Objective = EObjectiveType::PUSH;
	AllObjects.push_back(Baba2.get());

	GMapManager->SetObject(Baba.get(), 0, 0);
	GMapManager->SetObject(Baba2.get(), 1, 0);

	for (int i = 1; i <= 9; i++)
	{
		std::shared_ptr<AWallObject> WallTest = GetWorld()->SpawnActor<AWallObject>("Wall");
		WallTest->SetMapScale(UContentsConstValue::Stage1MapScale);
		WallTest->SetMaxIndex();
		WallTest->SetActorScale3D(UContentsConstValue::TileScale);
		WallTest->SetActorLocation(WallTest->CalIndexToPos(Index2D(i, i)));
		WallTest->BeginPosSetting();
		//WallTest->Info->Objective = EObjectiveType::STOP;
		WallTest->Info->Objective = EObjectiveType::PUSH;

		GMapManager->SetObject(WallTest.get(), i, i);
		AllObjects.push_back(WallTest.get());
	}
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