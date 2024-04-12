#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include <EngineCore/Camera.h>
#include "Background.h"
#include <EngineCore/EngineCore.h>
#include "StageSelecter.h"
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

	std::shared_ptr<AStageSelecter> Selecter = GetWorld()->SpawnActor<AStageSelecter>("Selecter");
	Selecter->SetMapScale(UContentsConstValue::StageSelectMapScale);
	Selecter->AddActorLocation(Selecter->CalIndexToPos(Index2D(0, 0)));
	Selecter->SetActorScale3D(UContentsConstValue::TileScale);

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorLocation({ 0, 0, 400 });
	Back->SetActorScale3D(UContentsConstValue::StageSelectMapImgScale);
	Back->SelectStageSetting();
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("Stage1Level");
	}
}

