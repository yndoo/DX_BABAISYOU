#include "PreCompile.h"
#include "GrassObject.h"

AGrassObject::AGrassObject()
{
}

AGrassObject::~AGrassObject()
{
}

void AGrassObject::BeginPlay()
{
	Super::BeginPlay();
	SetTileName("GRASS");
	CreateAnimations();
}

void AGrassObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}