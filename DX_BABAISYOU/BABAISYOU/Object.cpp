#include "PreCompile.h"
#include "Object.h"
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"
#include "MapManager.h"

AObject::AObject()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	SetRoot(Root);

	//Root->AddScale(FVector(54, 54, 1));
}

AObject::~AObject()
{
}

void AObject::BeginPlay()
{
	Super::BeginPlay();

	Info = new ObjectInfo();
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
	Index2D CurI = CalPosToIndex(_Cur);
	Index2D NxtI = CalPosToIndex(_Next);

	// Info �ٲ��ֱ�
	Info->CurIdx = NxtI;

	// GMM�� Graph ���� �ִ� ������ �����
	std::list<AObject*> ObjLst = GMapManager->Graph[CurI.X][CurI.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		if (*Iter == static_cast<AObject*>(this))
		{
			GMapManager->Graph[CurI.X][CurI.Y].remove(this);
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

// _Dir ������ _Nextĭ�� �� �� �ִ��� üũ�ϴ� �Լ� (Next�� STOP���� ���ִ� �Լ��̱⵵ ��)
bool AObject::CanGoNextTile(Index2D _Next, EInputDir _Dir)
{
	// �� �ű�� ��� 1. �� �Ѿ
	if (true == IndexRangeOverCheck(_Next))
	{
		return false;
	}

	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		// �� �ű�� ��� 2. �� �ű�� ���.
		if ((*Iter)->Info->Objective == EObjectiveType::STOP)
		{
			return false;
		}
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
		{
			// PUSH�� �ִ� ��į?
			// AllPushNextTile ����� true�� �о��ְ� ��?
		}
	}

	// ������ �ϳ��� �� �ɷ����� �̵� ����.
	return true;
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
	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		// �� �ű�� ��� 2. ���� ����� �� �ű�� ���.
		if ((*Iter)->Info->Objective == EObjectiveType::STOP)
		{
			return false;
		}
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
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
	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
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

	std::list<AObject*> ObjLst = GMapManager->Graph[_Next.X][_Next.Y];
	std::list<AObject*>::iterator Iter;
	for (Iter = ObjLst.begin(); Iter != ObjLst.end(); Iter++)
	{
		// PUSH�� �ִ� �� ���� ��� �о��ֱ�.
		if ((*Iter)->Info->Objective == EObjectiveType::PUSH)
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
	MoveStack.push(std::make_tuple(AnimationNumber, NewInputDir, true));
}

void AObject::PushFalseHistory()
{
	MoveStack.push(std::make_tuple(AnimationNumber, NewInputDir, false));
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