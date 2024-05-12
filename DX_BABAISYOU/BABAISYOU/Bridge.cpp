#include "PreCompile.h"
#include "Bridge.h"
#include <EngineCore/DefaultSceneComponent.h>
#include "ContentsEnum.h"

ABridge::ABridge()
{
	InputOff();
	Info->MyType = EObjectType::LINE;
}

ABridge::~ABridge()
{
}

void ABridge::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("LINE");
	CreateAnimations();
}

void ABridge::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (
		(Info->CurIndex == Index2D(3, 1) || Info->CurIndex == Index2D(4, 3) || Info->CurIndex == Index2D(5, 3) || Info->CurIndex == Index2D(6, 4) || Info->CurIndex == Index2D(5, 5)) 
		&& true == Renderer->IsActive()
		)
	{
		Renderer->SetActive(false);
	}
}