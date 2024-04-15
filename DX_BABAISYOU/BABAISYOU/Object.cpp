#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"

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
}

Index2D AObject::CalPosToIndex(FVector _Pos)
{
	Index2D Index;

	// �ε��� �ٰ��� ���� �Ʒ��� ������� ��ǥ�� ������ ���� ����ٰ� �����ϰ� ����
	_Pos.X += MapScale.hX();	
	_Pos.Y += MapScale.hY();

	_Pos -= FVector(UContentsConstValue::ITileX / 2, UContentsConstValue::ITileY / 2);

	Index.X = _Pos.X / UContentsConstValue::ITileX;
	Index.Y = _Pos.Y / UContentsConstValue::ITileY;


	return Index;
}

FVector AObject::CalIndexToPos(Index2D _Index)
{
	if (MapScale.X == 0 && MapScale.Y == 0)
	{
		MsgBoxAssert("MapScale�� 0, 0��");
	}

	FVector Pos = FVector::Zero;
	Pos.X -= MapScale.hX();
	Pos.Y -= MapScale.hY();

	Pos.X += _Index.X * UContentsConstValue::ITileX;
	Pos.Y += _Index.Y * UContentsConstValue::ITileY;

	Pos += FVector(UContentsConstValue::ITileX / 2, UContentsConstValue::ITileY / 2);

	return Pos;
}

Index2D AObject::GetMaxIndex()
{
	Index2D Result;
	Result.X = MapScale.iX() / UContentsConstValue::ITileX - 1;
	Result.Y = MapScale.iY() / UContentsConstValue::ITileY - 1;

	return Result;
}

void AObject::SetMaxIndex()
{
	Index2D MaxIndex = GetMaxIndex();

	UContentsConstValue::MaxIndexX = MaxIndex.X;
	UContentsConstValue::MaxIndexY = MaxIndex.Y;
}