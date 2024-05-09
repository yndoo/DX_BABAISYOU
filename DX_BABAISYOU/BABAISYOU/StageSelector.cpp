#include "PreCompile.h"
#include "StageSelector.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>
#include "MapManager.h"
#include "ContentsConstValue.h"

AStageSelector::AStageSelector()
{
	InputOn();
	Info->MyObjectiveType[EObjectType::YOU] = true;
}

AStageSelector::~AStageSelector()
{
}

void AStageSelector::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Selector", "Selector.png", 0.2f);
	Renderer->ChangeAnimation("Selector");
	Renderer->SetOrder(ERenderOrder::Player);
}

void AStageSelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int CurStageNum = IndexToStage(Info->CurIndex);
	if(MyCurStageNum != CurStageNum)
	{
		switch (CurStageNum)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			MakeTitle(CurStageNum);
			break;
		default:
			Title->SetActive(false);
			break;
		}

		MyCurStageNum = CurStageNum;
	}
}

bool AStageSelector::CanGoNextAll(Index2D _Next, EInputDir _Dir)
{
	// �� �ű�� ��� 1. �� �Ѿ
	if (true == IndexRangeOverCheck(_Next))
	{
		return false;
	}
	
	// _Next��ġ�� �������� ��ȣ �˾Ƴ��� -> ������� ���̸� �̵� ����
	int CurStageNum = IndexToStage(_Next);
	if (true == UContentsConstValue::MadeStages[CurStageNum])
	{
		return true;
	}

	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		// �� �ű�� ��� 2. �������� ��ȣ�� ���� Line�� ���� ����ִ� ��
		if ((*Iter)->Info->MyType == EObjectType::LINE)
		{
			// Line(Bridge) �ִ� ���� �� �� ����.
			return true;
		}

		// ��� NextNext �˻��� �ʿ� X
	}

	// �ϳ��� �� �ɷ����� �̵� �Ұ���.
	return false;
}

int AStageSelector::IndexToStage(Index2D _index)
{
	int Result = -1;
	if (Index2D(3, 1) == _index)
	{
		Result = 0;
	}
	else if (Index2D(4, 3) == _index)
	{
		Result = 1;
	}
	else if (Index2D(4, 4) == _index)
	{
		Result = 2;
	}
	else if (Index2D(5, 3) == _index)
	{
		Result = 3;
	}
	else if (Index2D(5, 4) == _index)
	{
		Result = 4;
	}
	else if (Index2D(4, 5) == _index)
	{
		Result = 5;
	}
	else if (Index2D(6, 4) == _index)
	{
		Result = 6;
	}
	else if (Index2D(5, 5) == _index)
	{
		Result = 7;
	}
	else if (Index2D(11, 8) == _index)
	{
		Result = 8;
	}
	else
	{
		//	MsgBoxAssert("���� �� ���� �������� ��ȣ");
		return -1;
	}

	return Result;
}

void AStageSelector::MakeTitle(int StageNum)
{
	if (nullptr != Title)
	{
		Title->SetActive(false);
	}
	Title = CreateWidget<UImage>(GetWorld(), "Title");
	Title->AddToViewPort(1);
	std::string str = "Title0" + std::to_string(StageNum) + ".png";
	Title->SetSprite(str);
	Title->SetAutoSize(0.85f, true);
	Title->SetPosition(FVector(-610, 355));
	FVector HalfDown = FVector(Title->GetLocalScale().hX(), -Title->GetLocalScale().hY());
	Title->AddPosition(HalfDown);
}