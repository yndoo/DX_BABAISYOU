#include "PreCompile.h"
#include "Stage1GameMode.h"
#include <EngineCore/Camera.h>
#include "BabaObject.h"
#include "MapManager.h"
#include "WallObject.h"
#include "Background.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"



AStage1GameMode::AStage1GameMode()
{
}

AStage1GameMode::~AStage1GameMode()
{
}

void AStage1GameMode::BeginPlay()
{
	Super::BeginPlay();
	Stage1MapSetting();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -200.0f));

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);

	Stage1MapSetting();	// 맵 오브젝트 세팅하는 곳

	std::list<std::shared_ptr<AObject>>* obj = MM->GetObjectList(0, 0);
	int a = 0;
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void AStage1GameMode::Stage1MapSetting()
{
	MM = std::make_shared<MapManager>();

	std::shared_ptr<ABabaObject> Baba2 = GetWorld()->SpawnActor<ABabaObject>("Baba");
	// 얘네는 같은 게임모드인 모든 Object 같이 세팅해야하는 것들
	Baba2->SetMapScale(UContentsConstValue::Stage1MapScale);
	Baba2->SetMaxIndex();
	Baba2->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로
		
	Baba2->AddActorLocation(Baba2->CalIndexToPos(Index2D(20, 0)));
	Baba2->BeginPosSetting();
	Baba2->SetOrder(ERenderOrder::FrontTile);
	//Baba2->SetName("ttttttttttttttt");


	std::shared_ptr<ABabaObject> Baba = GetWorld()->SpawnActor<ABabaObject>("Baba");
	// 얘네는 같은 게임모드인 모든 Object 같이 세팅해야하는 것들
	Baba->SetMapScale(UContentsConstValue::Stage1MapScale);
	Baba->SetMaxIndex();
	Baba->SetActorScale3D(UContentsConstValue::TileScale);	// 이미지 한 칸 크기 그대로

	Baba->AddActorLocation(Baba->CalIndexToPos(Index2D(0, 0)));
	Baba->BeginPosSetting();
	Baba->SetOrder(ERenderOrder::FrontTile);

	MM->SetObject(Baba, 0, 0);

	for (int i = 1; i <= 9; i++)
	{
		std::shared_ptr<AWallObject> WallTest = GetWorld()->SpawnActor<AWallObject>("Wall");
		WallTest->SetMapScale(UContentsConstValue::Stage1MapScale);
		WallTest->SetMaxIndex();
		WallTest->SetActorScale3D(UContentsConstValue::TileScale);
		WallTest->SetActorLocation(WallTest->CalIndexToPos(Index2D(i, i)));
		WallTest->BeginPosSetting();

		MM->SetObject(WallTest, i, i);
	}
}