#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>

AObject::AObject()
{
	
}

AObject::~AObject()
{
}

//void AObject::BeginPlay()
//{
//	WinScale = GEngine->EngineWindow.GetWindowScale();
//}
//
//Index2D AObject::PosToIndex(FVector _Pos)
//{
//	Index2D Index;
//
//	//_Pos -= WinScale.Half2D();	// ���� ���� �����
//	_Pos += FVector(18, 18);	// �� Ÿ���� �߾����� ���ܵ�
//
//	/*Index.X = WinScale.X / _Pos.X;
//	Index.Y = WinScale.Y / _Pos.Y;*/
//
//	Index.X = _Pos.X / 36;
//	Index.Y = _Pos.Y / 36;
//
//	return Index;
//}