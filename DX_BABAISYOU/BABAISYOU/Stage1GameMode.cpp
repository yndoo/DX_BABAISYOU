#include "PreCompile.h"
#include "Stage1GameMode.h"
#include <EngineCore/Camera.h>
#include "BabaObject.h"
#include "MapManager.h"
#include "WallObject.h"

AStage1GameMode::AStage1GameMode()
{
}

AStage1GameMode::~AStage1GameMode()
{
}

void AStage1GameMode::BeginPlay()
{
	Super::BeginPlay();
	Stage1MapSetting();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<ABabaObject> Baba = GetWorld()->SpawnActor<ABabaObject>("Baba");
	Baba->SetActorLocation(FVector(18, 18));
	Baba->SetActorScale3D(FVector(36.f, 36.f, 0.0f));	// 이미지 한 칸 크기 그대로

	//std::shared_ptr<AWallObject> WallTest = GetWorld()->SpawnActor<AWallObject>("Wall");
	//WallTest->SetActorScale3D(FVector(36.f, 36.f, -100.0f));

	Stage1MapSetting();
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void AStage1GameMode::Stage1MapSetting()
{
	// 테스트용
	FVector Center = FVector(18, 18);
	for (int i = 1; i <= 9; i++)
	{
		std::shared_ptr<AWallObject> WallTest = GetWorld()->SpawnActor<AWallObject>("Wall");
		WallTest->SetActorScale3D(FVector(36.f, 36.f, -100.0f));
		Center = Center + FVector(36, 0, 0);
		WallTest->SetActorLocation(Center);
	}
}