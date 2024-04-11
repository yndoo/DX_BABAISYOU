#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>

AObject::AObject()
{
	
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();
	WinScale = GEngine->EngineWindow.GetWindowScale();
}

Index2D AObject::PosToIndex(FVector _Pos)
{
	Index2D Index;

	// �ε��� �ٰ��� ���� ���� �����
	_Pos.X += WinScale.hX();	
	_Pos.Y -= WinScale.hY();
	_Pos += FVector(18, 18);	// �� Ÿ���� �߾����� ���ܵ�

	Index.X = _Pos.X / 36;
	Index.Y = -_Pos.Y / 36;

	return Index;
}