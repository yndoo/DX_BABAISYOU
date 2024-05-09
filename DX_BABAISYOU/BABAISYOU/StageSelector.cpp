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
	Renderer->SetOrder(ERenderOrder::UI);
}

void AStageSelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}

bool AStageSelector::CanGoNextAll(Index2D _Next, EInputDir _Dir)
{
	// 못 옮기는 경우 1. 벽 넘어감
	if (true == IndexRangeOverCheck(_Next))
	{
		return false;
	}
	
	// _Next위치의 스테이지 번호 알아내기 -> 만들어진 곳이면 이동 가능
	int CurStageNum = IndexToStage(_Next);
	if (true == UContentsConstValue::MadeStages[CurStageNum])
	{
		return true;
	}

	std::list<AObject*>::iterator Iter;
	for (Iter = GMapManager->Graph[_Next.X][_Next.Y].begin(); Iter != GMapManager->Graph[_Next.X][_Next.Y].end(); Iter++)
	{
		// 못 옮기는 경우 2. 스테이지 번호도 없고 Line도 없이 비어있는 곳
		if ((*Iter)->Info->MyType == EObjectType::LINE)
		{
			// Line(Bridge) 있는 곳은 갈 수 있음.
			return true;
		}

		// 얘는 NextNext 검사할 필요 X
	}

	// 하나도 안 걸렸으면 이동 불가능.
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
		//	MsgBoxAssert("아직 안 만든 스테이지 번호");
		return -1;
	}

	return Result;
}