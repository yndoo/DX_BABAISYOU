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
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);

	LoadMapFile("Stage2");

	Update();
}

void AStage2GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}
