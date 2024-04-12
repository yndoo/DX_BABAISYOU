#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"


AObject::AObject()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	//Root->SetScale(FVector(100, 1, 1, 1));
	SetRoot(Root);
	AddActorScale3D(FVector(100, 1, 1, 1));
	//SetActorScale3D(FVector(100, 1, 1, 1));
	
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();
	MapScale = ContentsConstValue::Stage1MapScale;	// 일단 하나만
}

Index2D AObject::PosToIndex(FVector _Pos)
{
	Index2D Index;

	// 인덱스 다같이 왼쪽 아래로 땡기려면 좌표를 오른쪽 위로 땡긴다고 생각하고 정리
	_Pos.X += MapScale.hX();	
	_Pos.Y += MapScale.hY();

	Index.X = _Pos.X / 36;
	Index.Y = _Pos.Y / 36;

	return Index;
}

FVector AObject::IndexToPos(Index2D _Index)
{
	FVector Pos = FVector::Zero;
	Pos.X -= MapScale.hX();
	Pos.Y -= MapScale.hY();

	Pos.X += _Index.X * 36;
	Pos.Y += _Index.Y * 36;

	Pos += FVector(18, 18);

	return Pos;
}