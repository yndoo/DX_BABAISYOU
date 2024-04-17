#include "PreCompile.h"
#include "BabaText.h"

ABabaText::ABabaText()
{
	Info->TileType = ETileType::Subject;
	Info->MyType = EObjectType::BABATEXT;
}

ABabaText::~ABabaText()
{
}

void ABabaText::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("BABATEXT_White", "BABA.png", AnimationInterVec, { 0, 17, 34 }, true);
	Renderer->CreateAnimation("BABATEXT_Purple", "BABAText.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("BABATEXT_Pink", "BABAText.png", AnimationInterVec, { 1, 3, 5 }, true);
	Renderer->ChangeAnimation("BABATEXT_Pink");

	CurObjType = Info->ObjectiveType;
}

void ABabaText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (CurObjType != Info->ObjectiveType)
	{
		CurObjType = Info->ObjectiveType;
	}
}