#include "PreCompile.h"
#include "SelectMapGameMode.h"
#include <EngineCore/Camera.h>
#include "Background.h"
#include <EngineCore/EngineCore.h>
#include "MapSelecter.h"

ASelectMapGameMode::ASelectMapGameMode()
{
	InputOn();
}

ASelectMapGameMode::~ASelectMapGameMode()
{
}

void ASelectMapGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorLocation({ 0, 0, 500 });

	std::shared_ptr<AMapSelecter> Selecter = GetWorld()->SpawnActor<AMapSelecter>("Selecter");
	Selecter->SetActorLocation({ 0, 0, 400 });	//¾ê°¡¾ÕÀÓ
}

void ASelectMapGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("Stage1Level");
	}
}