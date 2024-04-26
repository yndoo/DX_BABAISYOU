#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include <EngineCore/Camera.h>
#include <EngineCore/EngineCore.h>
#include "Background.h"
#include "StageSelector.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"
#include "Object.h"
#include "MapManager.h"

AStageSelectGameMode::AStageSelectGameMode()
{
	InputOn();
}

AStageSelectGameMode::~AStageSelectGameMode()
{
}

void AStageSelectGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	//std::shared_ptr<AStageSelector> Selector = GetWorld()->SpawnActor<AStageSelector>("Selector");
	//Selector->SetMapScale(UContentsConstValue::StageSelectMapScale);
	//Selector->AddActorLocation(Selector->CalIndexToPos(Index2D(0, 0)));
	//Selector->BeginPosSetting();
	//Selector->SetActorScale3D(UContentsConstValue::TileScale);

	//std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	//Back->SetActorLocation({ 0, 0, 400 });
	//Back->SetActorScale3D(UContentsConstValue::StageSelectMapImgScale);
	//Back->SelectStageSetting();

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("Stage1Level");
	}

	GMapManager->Graph;
	int a = 0;
}

void AStageSelectGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	LoadMapFile("Test1");
}

void AStageSelectGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}