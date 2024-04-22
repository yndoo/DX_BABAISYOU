#include "PreCompile.h"
#include "WallObject.h"
#include <EngineCore/EngineDebugMsgWindow.h>

AWallObject::AWallObject()
{
	Info->MyType = EObjectType::WALL;
}

AWallObject::~AWallObject()
{
}

void AWallObject::BeginPlay()
{
	Super::BeginPlay();
	CreateWallAnimations();

	std::string ani = "WALL" + std::to_string(TileNum);
	Renderer->ChangeAnimation(ani);
}

void AWallObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (TileNum != CurTileNum)
	{
		std::string ani = "WALL" + std::to_string(TileNum);
		Renderer->ChangeAnimation(ani);
		CurTileNum = TileNum;
	}
}

void AWallObject::CreateWallAnimations()
{
	// WALL 방향 종류가 0~15까지 (16개) 있음
	for (int i = 0; i < 16; i++)
	{
		Renderer->CreateAnimation("WALL" + std::to_string(i), "WALL.png", AnimationInterVec, { i + 2, i + 2 + 18, i + 2 + 18 * 2 });
	}
}