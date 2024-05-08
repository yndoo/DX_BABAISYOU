#include "PreCompile.h"
#include "TileObject.h"
#include "ContentsConstValue.h"
#include "MapManager.h"

ATileObject::ATileObject()
{
	Renderer->SetOrder(ERenderOrder::FrontTile);
	Info->TileType = ETileType::Tile;
}

ATileObject::~ATileObject()
{
}

void ATileObject::BeginPlay()
{
	Super::BeginPlay();
}

void ATileObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	TileDirUpdate();

	if (TileNum != CurTileNum)
	{
		std::string ani = TileName + std::to_string(TileNum);
		Renderer->ChangeAnimation(ani);
		CurTileNum = TileNum;
	}
}

// 현재 위치에서 네 방향 체크해서 경우에 따라 애니메이션 업데이트시키기
// 우 좌 하 상
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

std::map<int, int> DirToAniNumMap =		// 16가지 방향을 애니메이션 번호랑 매칭
{
	{0, 0},
	{1, 1},
	{8, 2},
	{9, 3},
	{2, 4},
	{3, 5},
	{10, 6},
	{11, 7},
	{4, 8},
	{5, 9},
	{12, 10},
	{13, 11},
	{6, 12},
	{7, 13},
	{14, 14},
	{15, 15}
};

void ATileObject::TileDirUpdate()
{
	Index2D CurIdx = Info->CurIndex;
	int DirNum = 0;
	for(int i = 0; i < 4; i++)
	{
		int nx = CurIdx.X + dx[i];
		int ny = CurIdx.Y + dy[i];
		if (nx <0 || ny < 0 || nx > UContentsConstValue::MaxIndexX || ny > UContentsConstValue::MaxIndexY)
		{
			DirNum += MyPow(2, i);
			continue;
		}
		// 옆에 같은 타일이 있는지 확인
		for (AObject* obj : *(GMapManager->GetObjectList(nx, ny)))		
		{
			if (false == obj->Destroyed && obj->Info->MyType == Info->MyType)
			{
				DirNum += MyPow(2, i);	// 2의 i 제곱
			}
		}
	}
	TileNum = DirToAniNumMap[DirNum];
}

void ATileObject::CreateAnimations()
{
	// Tile은 방향 종류가 0~15까지 (16개) 있음
	for (int i = 0; i < 16; i++)
	{
		Renderer->CreateAnimation(TileName + std::to_string(i), TileName + ".png", AnimationInterVec, { i + 2, i + 2 + 18, i + 2 + 18 * 2 });
	}
}

int ATileObject::MyPow(int _Num, int _Pow)
{
	int Result = 1;
	for (int i = 0; i < _Pow; i++)
	{
		Result *= _Num;
	}

	return Result;
}