#include "PreCompile.h"
#include "BackTileObject.h"

ABackTileObject::ABackTileObject()
{
	Info->MyType = EObjectType::TILE;
	Renderer->SetOrder(ERenderOrder::BackTile);
}

ABackTileObject::~ABackTileObject()
{
}

void ABackTileObject::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Tile", "Tile.png", AnimationInterVec, { 0, 1, 2 }, true);
	Renderer->ChangeAnimation("Tile");
}