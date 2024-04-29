#include "PreCompile.h"
#include "StageNumber.h"
#include "ContentsConstValue.h"

AStageNumber::AStageNumber()
{
	Renderer->SetOrder(ERenderOrder::FrontTile);
}

AStageNumber::~AStageNumber()
{
}

void AStageNumber::BeginPlay()
{
	Super::BeginPlay();
	CreateNumAni();
}

void AStageNumber::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	FVector Pos = GetActorLocation();
	int a = 0;
}

void AStageNumber::LevelEnd(ULevel* _NextLevel)
{

}

void AStageNumber::LevelStart(ULevel* _PrevLevel)
{
	Renderer->ChangeAnimation(std::to_string(StageNum) + "_White");
}

void AStageNumber::CreateNumAni()
{
	// 0~9 애니메이션
	for (int i = 0; i <= 9; i++)
	{
		Renderer->CreateAnimation(std::to_string(i) + "_White", "NumberFont.png", AnimationInterVec, { i * 2 + 0, i * 2 + 10, i * 2 + 20 }, true);
		Renderer->CreateAnimation(std::to_string(i) + "_Gray", "NumberFont.png", AnimationInterVec, { i * 2 + 1, i * 2 + 11, i * 2 + 21 }, true);
	}
}