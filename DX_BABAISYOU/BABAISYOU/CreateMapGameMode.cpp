#include "PreCompile.h"
#include "CreateMapGameMode.h"
#include "MapManager.h"
#include "Background.h"
#include "ContentsConstValue.h"

CreateMapGameMode::CreateMapGameMode()
{
}

CreateMapGameMode::~CreateMapGameMode()
{
}

void CreateMapGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->Stage1Setting();
	Back->SetOrder(ERenderOrder::Background);
}

float UpdateTime = 0.f;
void CreateMapGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	if (true == UContentsConstValue::IsMapEditorUpdated)
	{
		LoadMapFile("Test1");
		UContentsConstValue::IsMapEditorUpdated = false;
	}

}


void CreateMapGameMode::LevelStart(ULevel* _PrevLevel)
{
	
}

void CreateMapGameMode::LevelEnd(ULevel* _NextLevel)
{
	//GMapManager->ClearGraph();
}