#include "PreCompile.h"
#include "StageGameMode.h"
#include "ContentsConstValue.h"

AStageGameMode::AStageGameMode()
{
}

AStageGameMode::~AStageGameMode()
{
}

void AStageGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AStageGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AStageGameMode::LevelStart(ULevel* _PrevLevel)
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

void AStageGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}
