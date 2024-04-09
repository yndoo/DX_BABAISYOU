#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include <EngineCore/Camera.h>
#include "Background.h"
#include <EngineCore/EngineCore.h>
#include "StageSelecter.h"

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
	Stage1MapSetting();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<AStageSelecter> Selecter = GetWorld()->SpawnActor<AStageSelecter>("Selecter");
	Selecter->SetActorLocation({ 0, 0, 400 });	//얘가앞임

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorLocation({ 0, 0, 400 });

}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("Stage1Level");
	}
}

void AStageSelectGameMode::Stage1MapSetting()
{
	//MapManager::Stage1로 체크용 맵 세팅
}