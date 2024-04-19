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
	Renderer->CreateAnimation("BABATEXT_Off", "BABAText.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("BABATEXT_On", "BABAText.png", AnimationInterVec, { 1, 3, 5 }, true);
	Renderer->ChangeAnimation("BABATEXT_On");

	CurObjType = Info->MyObjectiveType;
}

void ABabaText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MoveStack;
	int a = 0;
}

void ABabaText::AniONOFF()
{
	if (ON)
	{
		Renderer->ChangeAnimation("BABATEXT_On");
	}
	else
	{
		Renderer->ChangeAnimation("BABATEXT_Off");
	}
}