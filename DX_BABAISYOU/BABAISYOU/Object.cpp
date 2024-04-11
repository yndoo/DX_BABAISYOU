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

	// ¿Œµ¶Ω∫ ¥Ÿ∞∞¿Ã øﬁ¬  ¿ß∑Œ ∂Ø±‚±‚
	_Pos.X += WinScale.hX();	
	_Pos.Y -= WinScale.hY();
	_Pos += FVector(18, 18);	// «— ≈∏¿œ¿« ¡ﬂæ”¿∏∑Œ ∂Ø∞‹µ“

	Index.X = _Pos.X / 36;
	Index.Y = -_Pos.Y / 36;

	return Index;
}