#include "PreCompile.h"
#include "Stage1GameMode.h"
#include <EngineCore/Camera.h>
#include "BabaObject.h"

AStage1GameMode::AStage1GameMode()
{
}

AStage1GameMode::~AStage1GameMode()
{
}

void AStage1GameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	GetWorld()->SpawnActor<ABabaObject>("BabaObject");
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}