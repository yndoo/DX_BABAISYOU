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
	Baba->SetActorScale3D(FVector(36.f, 36.f, -100.0f));	// �̹��� �� ĭ ũ�� �״��

	
}

void AStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void AStage1GameMode::Stage1MapSetting()
{
	// MapManager::Stage1�� üũ�� �� ����
	// �ٱ� ��� ���� ���� � ����� ���� 24ĭ, ���� 18ĭ
	// �ƴϾ� �̰� ���� �����ҰǾƴѵ�
	//MapManager::Stage1[0][0] = static_cast<int>(EMapObjects::BABA);
}