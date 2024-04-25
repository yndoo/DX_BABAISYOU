#include "PreCompile.h"
#include "CreateMapGameMode.h"
#include "MapManager.h"

CreateMapGameMode::CreateMapGameMode()
{
}

CreateMapGameMode::~CreateMapGameMode()
{
}

void CreateMapGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void CreateMapGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


void CreateMapGameMode::LevelStart(ULevel* _PrevLevel)
{
	GMapManager->ClearGraph();
}

void CreateMapGameMode::LevelEnd(ULevel* _NextLevel)
{

}