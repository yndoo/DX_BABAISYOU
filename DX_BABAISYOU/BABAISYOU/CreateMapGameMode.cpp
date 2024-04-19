#include "PreCompile.h"
#include "CreateMapGameMode.h"

CreateMapGameMode::CreateMapGameMode()
{
}

CreateMapGameMode::~CreateMapGameMode()
{
}

void CreateMapGameMode::BeginPlay()
{
	Super::BeginPlay();

	//TileMap = GetWorld()->SpawnActor<ATileMap>("TileMap", ERenderOrder::Map);
}

void CreateMapGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
