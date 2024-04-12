#include "PreCompile.h"
#include "WallObject.h"

AWallObject::AWallObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AWallObject::~AWallObject()
{
}

void AWallObject::BeginPlay()
{
	Super::BeginPlay();
	CreateWallAnimations();

	Renderer->ChangeAnimation("WALL0");
}

void AWallObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWallObject::CreateWallAnimations()
{
	// WALL 방향 종류가 0~15까지 (16개) 있음
	for (int i = 0; i < 16; i++)
	{
		Renderer->CreateAnimation("WALL" + std::to_string(i), "WALL.png", AnimationInterVec, { i + 2, i + 2 + 18, i + 2 + 18 * 2 });
	}
}