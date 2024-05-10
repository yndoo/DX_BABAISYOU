#include "PreCompile.h"
#include "WaterObject.h"

AWaterObject::AWaterObject()
{
	Info->MyType = EObjectType::WATER;
	Info->TileType = ETileType::Tile;
	Info->MyColor = FVector(95, 157, 209);
}

AWaterObject::~AWaterObject()
{
}

void AWaterObject::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("WATER");
	CreateAnimations();
}

void AWaterObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (Destroyed != MyLife)
	{
		MyLife = Destroyed;
		if(true == Destroyed)
		{
			UEngineSound::SoundPlay("WaterSinkDead.ogg");
		}
	}
}
