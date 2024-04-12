#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/DefaultSceneComponent.h>

AObject::AObject()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	SetRoot(Root);
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();
	MapScale = FVector(864, 648);
}

Index2D AObject::PosToIndex(FVector _Pos)
{
	Index2D Index;

	// �ε��� �ٰ��� ���� �Ʒ��� ������� ��ǥ�� ������ ���� ����ٰ� �����ϰ� ����
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