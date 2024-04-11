#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include <EngineCore/Camera.h>
#include "Background.h"
#include <EngineCore/EngineCore.h>
#include "StageSelecter.h"
#include "ContentsEnum.h"

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
	Selecter->SetActorLocation({ 0, 0, 400 });	//¾ê°¡¾ÕÀÓ
	Selecter->SetActorScale3D({ 36, 36, 1 });
	//Selecter->SetOrder(ERenderOrder::FrontTile);

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorLocation({ 0, 0, 400 });
	Back->SetActorScale3D(FVector(1280.0f * 1.3f * 0.9f, 720.0f * 2.45f * 0.8f, 1.0f));
	Back->SelectStageSetting();
	//Back->SetOrder(ERenderOrder::Background);
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("Stage1Level");
	}
}

