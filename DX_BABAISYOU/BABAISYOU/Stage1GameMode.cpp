#include "PreCompile.h"
#include "Stage1GameMode.h"
#include <EngineCore/Camera.h>
#include "BabaObject.h"
#include "MapManager.h"

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
	Baba->SetActorScale3D(FVector(36.f, 36.f, -100.0f));	// 이미지 한 칸 크기 그대로

	
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void AStage1GameMode::Stage1MapSetting()
{
	// MapManager::Stage1로 체크용 맵 세팅
	// 바깥 배경 말고 내부 까만 배경이 가로 24칸, 세로 18칸
	// 아니야 이건 보류 당장할건아닌듯
	//MapManager::Stage1[0][0] = static_cast<int>(EMapObjects::BABA);
}