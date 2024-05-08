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

void AStageNumber::SetRendererMulColor(FVector _Color)
{
	_Color /= 255;
	Renderer->SetMulColor(_Color);
}

void AStageNumber::CreateNumAni()
{
	// 0~4 애니메이션
	for (int i = 0; i <= 4; i++)
	{
		Renderer->CreateAnimation(std::to_string(i) + "_White", "NumberFont.png", AnimationInterVec, { i * 2 + 0, i * 2 + 10, i * 2 + 20 }, true);
		Renderer->CreateAnimation(std::to_string(i) + "_Gray", "NumberFont.png", AnimationInterVec, { i * 2 + 1, i * 2 + 11, i * 2 + 21 }, true);
	}
	// 5~9
	for (int i = 0; i <= 4; i++)
	{
		int j = i * 2 + 30;
		Renderer->CreateAnimation(std::to_string(i + 5) + "_White", "NumberFont.png", AnimationInterVec, { j + 0, j + 10, j + 20 }, true);
		Renderer->CreateAnimation(std::to_string(i + 5) + "_Gray", "NumberFont.png", AnimationInterVec, { j + 1, j + 11, j + 21 }, true);
	}
}