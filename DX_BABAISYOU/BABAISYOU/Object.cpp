#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"
#include "MapManager.h"
#include  <map>

AObject::AObject()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	SetRoot(Root);

	Root->AddScale(FVector(54, 54, 1));

	Info = new ObjectInfo();
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();
}

void AObject::BeginPosSetting()
{
	// ������ �ֵ� Location �������ְ��� �ٽ� �������.
	CurActorLocation = GetActorLocation();
	Info->CurIndex = CalPosToIndex(CurActorLocation);
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

// ���� _Cur��ġ���� ����� _Next��ġ�� ������ �� �Ű��ִ� �Լ�. 
void AObject::CurToNext(FVector _Cur, FVector _Next)
{
	Index2D CurI = Info->CurIndex;
	Index2D NxtI = CalPosToIndex(_Next);

	// Info �ٲ��ֱ�
	Info->CurIndex = NxtI;

	// GMM�� Graph ���� �ִ� ������ �����
	//std::list<AObject*> ObjLst = GMapManager->Graph[CurI.X][CurI.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[CurI.X][CurI.Y].begin(); Iter != GMapManager->Graph[CurI.X][CurI.Y].end(); Iter++)
	{
		if (*Iter == static_cast<AObject*>(this))
		{
			GMapManager->Graph[CurI.X][CurI.Y].remove(*Iter);
			break;
		}
	}

	// GMM�� Graph �� ��ġ�� �־��ֱ�
	GMapManager->Graph[NxtI.X][NxtI.Y].push_back(static_cast<AObject*>(this));
}


// ���� �Ѿ���� üũ. true : �Ѿ
bool AObject::IndexRangeOverCheck(Index2D Idx)
{
	if (Idx.X < 0 || Idx.Y < 0 || Idx.X > UContentsConstValue::MaxIndexX || Idx.Y > UContentsConstValue::MaxIndexY)
	{
		return true;
	}

	return false;
}

// _Dir ������ _Nextĭ�� �� �� �� �ִ��� "üũ"�ϴ� �Լ�
bool AObject::CanGoNextAll(Index2D _Next, EInputDir _Dir)
{
	// �� �ű�� ��� 1. �� �Ѿ
	if (true == IndexRangeOverCheck(_Next))
	{
		return false;
	}

	// _Next�� �� �� ������ �ϳ��� ���� üũ�ؾ� ��
	//std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		// �� �ű�� ��� 2. ���� ����� �� �ű�� ���.
		if ((*Iter)->Info->ObjectiveType == EObjectType::STOP)
		{
			return false;
		}
		if (
			(*Iter)->Info->ObjectiveType == EObjectType::PUSH ||
			(*Iter)->Info->TileType == ETileType::Subject ||
			(*Iter)->Info->TileType == ETileType::Verb || 
			(*Iter)->Info->TileType == ETileType::Objective
			)
		{
			// PUSH�� �ִ� �� ���� ��� üũ.
			Index2D NextNext = _Next;
			switch (_Dir)
			{
			case EInputDir::Right:
				NextNext.X += 1;
				break;
			case EInputDir::Left:
				NextNext.X -= 1;
				break;
			case EInputDir::Up:
				NextNext.Y += 1;
				break;
			case EInputDir::Down:
				NextNext.Y -= 1;
				break;
			default:
				break;
			}

			if (false == (*Iter)->CanGoNextAll(NextNext, _Dir))
			{
				return false;
			}
		}
	}

	// �ϳ��� �� �ɷ����� �̵� ����.
	return true;
}

// �� ĭ�� PUSH���� Ȯ���ϴ� �Լ�
bool AObject::IsNextPUSH(Index2D _Next)
{
	//std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		if (
			(*Iter)->Info->ObjectiveType == EObjectType::PUSH ||
			(*Iter)->Info->TileType == ETileType::Subject ||
			(*Iter)->Info->TileType == ETileType::Verb ||
			(*Iter)->Info->TileType == ETileType::Objective
			)
		{
			return true;
		}
	}

	return false;
}

// _Dir ������ _Nextĭ�� �б�(��¥ �б� �ൿ)(�� �� �ִ� ��쿡�� ����ؾ� ��)
void AObject::AllPushNextTile(Index2D _Next, EInputDir _Dir)
{
	std::list<std::pair<AObject*, Index2D>> PushList;
	//std::map<AObject*, Index2D> PushList;

	//std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		// PUSH�� �ִ� �� ���� ��� �о��ֱ�.
		if (
			(*Iter)->Info->ObjectiveType == EObjectType::PUSH ||
			(*Iter)->Info->TileType == ETileType::Subject ||
			(*Iter)->Info->TileType == ETileType::Verb ||
			(*Iter)->Info->TileType == ETileType::Objective
			)
		{
			Index2D NextNext = _Next;
			switch (_Dir)
			{
			case EInputDir::Right:
				NextNext.X += 1;
				break;
			case EInputDir::Left:
				NextNext.X -= 1;
				break;
			case EInputDir::Up:
				NextNext.Y += 1;
				break;
			case EInputDir::Down:
				NextNext.Y -= 1;
				break;
			default:
				break;
			}

			PushList.push_back(std::make_pair(*Iter, NextNext));
			//PushList[*Iter] = NextNext;
			(*Iter)->AllPushNextTile(NextNext, _Dir);
		}
	}

	for (auto PO : PushList)
	{
		PO.first->CurToNext(CalIndexToPos(_Next), CalIndexToPos(PO.second));
		PO.first->NewInputDir = _Dir;
	}
}

void AObject::PushTrueHistory()
{
	MoveStack.push(std::make_pair(NewInputDir, true));
	AnimationStack.push(std::make_pair((AnimationNumber - 1 + 4) % 4, BeforeDir));
	int a = 0;
}

void AObject::PushFalseHistory()
{
	MoveStack.push(std::make_pair(NewInputDir, false));
}

bool AObject::DirCheck()
{
	if (CurDir != NewInputDir)
	{
		CurDir = NewInputDir;
		return true;
	}
	return false;
}