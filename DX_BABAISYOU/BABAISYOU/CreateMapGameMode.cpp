#include "PreCompile.h"
#include "CreateMapGameMode.h"
#include "MapManager.h"
#include "Background.h"
#include "ContentsConstValue.h"

ACreateMapGameMode::ACreateMapGameMode()
{
}

ACreateMapGameMode::~ACreateMapGameMode()
{
}

void ACreateMapGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::Stage0MapScale);
	CurMapScale = Back->GetActorScale3D();
	Back->SetActorLocation({ 0, 0, 400 });
	Back->BGImageSetting();
	Back->SetOrder(ERenderOrder::Background);

}

float UpdateTime = 0.f;
void ACreateMapGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


void ACreateMapGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void ACreateMapGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}