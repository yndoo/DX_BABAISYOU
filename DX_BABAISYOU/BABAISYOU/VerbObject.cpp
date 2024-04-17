#include "PreCompile.h"
#include "VerbObject.h"
#include "ContentsConstValue.h"

AVerbObject::AVerbObject()
{
	Info->ObjectiveType = EObjectType::PUSH;
	Info->TileType = ETileType::Verb;
}

AVerbObject::~AVerbObject()
{
}

void AVerbObject::BeginPlay()
{
	Super::BeginPlay();
	BeginPosSetting();
}

void AVerbObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}