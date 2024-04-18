#include "PreCompile.h"
#include "Stage1GameMode.h"
#include <EngineCore/Camera.h>
#include "BabaObject.h"
#include "MapManager.h"
#include "WallObject.h"
#include "Background.h"
#include "IsText.h"
#include "BabaText.h"
#include "YouText.h"
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
	Update();
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
	//Baba->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로
	AllObjects.push_back(Baba.get());
	Players.push_back(Baba.get());
	GMapManager->SetObject(Baba.get(), 0, 0);

	Baba->AddActorLocation(Baba->CalIndexToPos(Index2D(0, 0)));
	Baba->BeginPosSetting();
	Baba->SetOrder(ERenderOrder::FrontTile);
	Baba->Info->ObjectiveType = EObjectType::YOU;	//임시 테스트임


	std::shared_ptr<ABabaObject> Baba2 = GetWorld()->SpawnActor<ABabaObject>("Baba");
	// 얘네는 같은 게임모드인 모든 Object 같이 세팅해야하는 것들
	Baba2->SetMapScale(UContentsConstValue::Stage1MapScale);
	Baba2->SetMaxIndex();
	//Baba2->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로
	AllObjects.push_back(Baba2.get());
	Players.push_back(Baba2.get());
	GMapManager->SetObject(Baba2.get(), 1, 0);

	Baba2->AddActorLocation(Baba2->CalIndexToPos(Index2D(1, 0)));
	Baba2->BeginPosSetting();
	Baba2->SetOrder(ERenderOrder::FrontTile);


	std::shared_ptr<AIsText> IS = GetWorld()->SpawnActor<AIsText>("IS");
	IS->SetMapScale(UContentsConstValue::Stage1MapScale);
	IS->SetMaxIndex();
	//IS->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로
	AllObjects.push_back(IS.get());
	Texts.push_back(IS.get());
	GMapManager->SetObject(IS.get(), 10, 3);

	IS->AddActorLocation(IS->CalIndexToPos(Index2D(10, 3)));
	IS->BeginPosSetting();
	IS->SetOrder(ERenderOrder::FrontTile);


	std::shared_ptr<ABabaText> BaText = GetWorld()->SpawnActor<ABabaText>("BabaText");
	BaText->SetMapScale(UContentsConstValue::Stage1MapScale);
	BaText->SetMaxIndex();
	AllObjects.push_back(BaText.get());
	Texts.push_back(BaText.get());
	GMapManager->SetObject(BaText.get(), 10, 4);
	BaText->AddActorLocation(BaText->CalIndexToPos(Index2D(10, 4)));
	BaText->BeginPosSetting();
	BaText->SetOrder(ERenderOrder::FrontTile);

	std::shared_ptr<AYouText> YOU = GetWorld()->SpawnActor<AYouText>("YOUText");
	YOU->SetMapScale(UContentsConstValue::Stage1MapScale);
	YOU->SetMaxIndex();
	AllObjects.push_back(YOU.get());
	Texts.push_back(YOU.get());
	GMapManager->SetObject(YOU.get(), 10, 2);
	YOU->AddActorLocation(YOU->CalIndexToPos(Index2D(10, 2)));
	YOU->BeginPosSetting();
	YOU->SetOrder(ERenderOrder::FrontTile);

	for (int i = 1; i <= 9; i++)
	{
		std::shared_ptr<AWallObject> WallTest = GetWorld()->SpawnActor<AWallObject>("Wall");
		WallTest->SetMapScale(UContentsConstValue::Stage1MapScale);
		WallTest->SetMaxIndex();
		//WallTest->SetActorScale3D(UContentsConstValue::TileScale);
		WallTest->SetActorLocation(WallTest->CalIndexToPos(Index2D(i, i)));
		WallTest->BeginPosSetting();
		//WallTest->Info->Objective = EObjectiveType::STOP;
		WallTest->Info->ObjectiveType = EObjectType::PUSH;

		GMapManager->SetObject(WallTest.get(), i, i);
		AllObjects.push_back(WallTest.get());
		Players.push_back(WallTest.get());
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