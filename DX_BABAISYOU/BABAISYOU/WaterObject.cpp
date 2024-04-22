#include "PreCompile.h"
#include "WaterObject.h"

AWaterObject::AWaterObject()
{
	Info->MyType = EObjectType::WATER;
}

AWaterObject::~AWaterObject()
{
}

void AWaterObject::BeginPlay()
{
	Super::BeginPlay();
	CreateWaterAnimations();

	std::string ani = "WATER" + std::to_string(TileNum);
	Renderer->ChangeAnimation(ani);
}

void AWaterObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (TileNum != CurTileNum)
	{
		std::string ani = "WATER" + std::to_string(TileNum);
		Renderer->ChangeAnimation(ani);
		CurTileNum = TileNum;
	}
}

void AWaterObject::CreateWaterAnimations()
{
	// WATER 방향 종류가 0~15까지 (16개) 있음
	for (int i = 0; i < 16; i++)
	{
		Renderer->CreateAnimation("WATER" + std::to_string(i), "WATER.png", AnimationInterVec, { i + 2, i + 2 + 18, i + 2 + 18 * 2 });
	}
}