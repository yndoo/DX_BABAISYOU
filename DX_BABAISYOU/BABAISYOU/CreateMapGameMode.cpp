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
	Back->SetActorScale3D(UContentsConstValue::Stage4MapScale);
	CurMapScale = Back->GetActorScale3D();
	Back->SetActorLocation({ 0, 0, 400 });
	Back->BGImageSetting();
	Back->SetOrder(ERenderOrder::Background);
}

float UpdateTime = 0.f;
void CreateMapGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


void CreateMapGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void CreateMapGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}