#include "PreCompile.h"
#include "Stage2GameMode.h"
#include "ContentsConstValue.h"

AStage2GameMode::AStage2GameMode()
{
}

AStage2GameMode::~AStage2GameMode()
{
}

void AStage2GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AStage2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AStage2GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorLocation({ 0, 0, 400 });
	Back->SetOrder(ERenderOrder::Background);
	Back->BGImageSetting();

	switch (UContentsConstValue::OpenStageNum)
	{
	case 1:
	case 2:
		Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
		break;
	case 3:
		Back->SetActorScale3D(UContentsConstValue::Stage3MapScale);
		break;
	default:
		break;
	}


	LoadMapFile("Stage"+std::to_string(UContentsConstValue::OpenStageNum));

	Update();
}

void AStage2GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}
