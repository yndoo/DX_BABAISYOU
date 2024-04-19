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
	Stage1MapSetting();	// �� ������Ʈ �����ϴ� ��

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
	/* ============= Player Object�� ============= */
	std::shared_ptr<ABabaObject> Baba = GetWorld()->SpawnActor<ABabaObject>("Baba");
	// ��״� ���� ���Ӹ���� ��� Object ���� �����ؾ��ϴ� �͵�
	Baba->SetMapScale(UContentsConstValue::Stage1MapScale);
	Baba->SetMaxIndex();
	//Baba->SetActorScale3D(UContentsConstValue::TileScale);	// �̹��� �� ĭ ũ�� �״��
	AllObjects.push_back(Baba.get());
	Players.push_back(Baba.get());
	GMapManager->SetObject(Baba.get(), 8, 4);

	Baba->AddActorLocation(Baba->CalIndexToPos(Index2D(8, 4)));
	Baba->BeginPosSetting();
	Baba->SetOrder(ERenderOrder::FrontTile);
	//Baba->Info->MyObjectiveType = EObjectType::YOU;	//�ӽ� �׽�Ʈ��


	//std::shared_ptr<ABabaObject> Baba2 = GetWorld()->SpawnActor<ABabaObject>("Baba");
	//// ��״� ���� ���Ӹ���� ��� Object ���� �����ؾ��ϴ� �͵�
	//Baba2->SetMapScale(UContentsConstValue::Stage1MapScale);
	//Baba2->SetMaxIndex();
	////Baba2->SetActorScale3D(UContentsConstValue::TileScale);	// �̹��� �� ĭ ũ�� �״��
	//AllObjects.push_back(Baba2.get());
	//Players.push_back(Baba2.get());
	//GMapManager->SetObject(Baba2.get(), 1, 0);

	//Baba2->AddActorLocation(Baba2->CalIndexToPos(Index2D(1, 0)));
	//Baba2->BeginPosSetting();
	//Baba2->SetOrder(ERenderOrder::FrontTile);

	for (int i = 1; i <= 9; i++)
	{
		std::shared_ptr<AWallObject> Wall = GetWorld()->SpawnActor<AWallObject>("Wall");
		Wall->SetMapScale(UContentsConstValue::Stage1MapScale);
		Wall->SetMaxIndex();
		//WallTest->SetActorScale3D(UContentsConstValue::TileScale);
		Wall->SetActorLocation(Wall->CalIndexToPos(Index2D(i, i)));
		Wall->BeginPosSetting();
		//WallTest->Info->Objective = EObjectiveType::STOP;
		//Wall->Info->MyObjectiveType = EObjectType::PUSH;

		GMapManager->SetObject(Wall.get(), i, i);
		AllObjects.push_back(Wall.get());
		Players.push_back(Wall.get());
	}

	std::shared_ptr<AFlagObject> Flag = GetWorld()->SpawnActor<AFlagObject>("Flag");
	Flag->SetMapScale(UContentsConstValue::Stage1MapScale);
	Flag->SetMaxIndex();
	Flag->SetActorLocation(Flag->CalIndexToPos(Index2D(8, 14)));
	Flag->BeginPosSetting();
	GMapManager->SetObject(Flag.get(), 8, 14);
	AllObjects.push_back(Flag.get());
	Players.push_back(Flag.get());

	/* ============= �־� Object�� ============= */
	std::shared_ptr<ABabaText> BaText = GetWorld()->SpawnActor<ABabaText>("BabaText");
	BaText->SetMapScale(UContentsConstValue::Stage1MapScale);
	BaText->SetMaxIndex();
	AllObjects.push_back(BaText.get());
	Texts.push_back(BaText.get());
	GMapManager->SetObject(BaText.get(), 10, 4);
	BaText->AddActorLocation(BaText->CalIndexToPos(Index2D(10, 4)));
	BaText->BeginPosSetting();
	BaText->SetOrder(ERenderOrder::FrontTile);

	std::shared_ptr<AWallText> WallText = GetWorld()->SpawnActor<AWallText>("WallText");
	WallText->SetMapScale(UContentsConstValue::Stage1MapScale);
	WallText->SetMaxIndex();
	AllObjects.push_back(WallText.get());
	Texts.push_back(WallText.get());
	GMapManager->SetObject(WallText.get(), 11, 4);
	WallText->AddActorLocation(WallText->CalIndexToPos(Index2D(11, 4)));
	WallText->BeginPosSetting();
	WallText->SetOrder(ERenderOrder::FrontTile);

	std::shared_ptr<AFlagText> FlagText = GetWorld()->SpawnActor<AFlagText>("FlagText");
	FlagText->SetMapScale(UContentsConstValue::Stage1MapScale);
	FlagText->SetMaxIndex();
	FlagText->SetActorLocation(FlagText->CalIndexToPos(Index2D(9, 4)));
	FlagText->BeginPosSetting();
	FlagText->SetOrder(ERenderOrder::FrontTile);
	GMapManager->SetObject(FlagText.get(), 9, 4);
	AllObjects.push_back(FlagText.get());
	Texts.push_back(FlagText.get());

	/* ============= ���� Object�� ============= */
	std::shared_ptr<AIsText> IS = GetWorld()->SpawnActor<AIsText>("IS");
	IS->SetMapScale(UContentsConstValue::Stage1MapScale);
	IS->SetMaxIndex();
	//IS->SetActorScale3D(UContentsConstValue::TileScale);	// �̹��� �� ĭ ũ�� �״��
	AllObjects.push_back(IS.get());
	Texts.push_back(IS.get());
	GMapManager->SetObject(IS.get(), 10, 3);

	IS->AddActorLocation(IS->CalIndexToPos(Index2D(10, 3)));
	IS->BeginPosSetting();
	IS->SetOrder(ERenderOrder::FrontTile);

	/* ============= ������ Object�� ============= */

	std::shared_ptr<AYouText> YOU = GetWorld()->SpawnActor<AYouText>("YOUText");
	YOU->SetMapScale(UContentsConstValue::Stage1MapScale);
	YOU->SetMaxIndex();
	AllObjects.push_back(YOU.get());
	Texts.push_back(YOU.get());
	GMapManager->SetObject(YOU.get(), 10, 2);
	YOU->AddActorLocation(YOU->CalIndexToPos(Index2D(10, 2)));
	YOU->BeginPosSetting();
	YOU->SetOrder(ERenderOrder::FrontTile);

	std::shared_ptr<AStopText> Stop = GetWorld()->SpawnActor<AStopText>("StopText");
	Stop->SetMapScale(UContentsConstValue::Stage1MapScale);
	Stop->SetMaxIndex();
	AllObjects.push_back(Stop.get());
	Texts.push_back(Stop.get());
	GMapManager->SetObject(Stop.get(), 12, 2);
	Stop->AddActorLocation(Stop->CalIndexToPos(Index2D(12, 2)));
	Stop->BeginPosSetting();
	Stop->SetOrder(ERenderOrder::FrontTile);

	std::shared_ptr<AWinText> Win = GetWorld()->SpawnActor<AWinText>("WinText");
	Win->SetMapScale(UContentsConstValue::Stage1MapScale);
	Win->SetMaxIndex();
	AllObjects.push_back(Win.get());
	Texts.push_back(Win.get());
	GMapManager->SetObject(Win.get(), 13, 2);
	Win->AddActorLocation(Win->CalIndexToPos(Index2D(13, 2)));
	Win->BeginPosSetting();
	Win->SetOrder(ERenderOrder::FrontTile);
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