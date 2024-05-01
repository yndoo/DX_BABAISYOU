#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include <EngineCore/Camera.h>
#include <EngineCore/EngineCore.h>
#include "Background.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"
#include "Object.h"
#include "MapManager.h"


AStageSelectGameMode::AStageSelectGameMode()
{
	InputOn();
}

AStageSelectGameMode::~AStageSelectGameMode()
{
}

void AStageSelectGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	Selector = GetWorld()->SpawnActor<AStageSelector>("Selector");
	Selector->SetMapScale(UContentsConstValue::StageSelectMapScale);
	Selector->AddActorLocation(Selector->CalIndexToPos(Index2D(4, 1)));
	Selector->BeginPosSetting();
	Selector->SetActorScale3D(UContentsConstValue::TileScale * 1.5);

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::StageSelectMapImgScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->SelectStageSetting();
	Back->SetOrder(ERenderOrder::Background);

	CurStage = UContentsConstValue::ClearStage;
	NewStage(0, 1);
	//NewStage(0, 2);
	//NewStage(0, 3);
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (UContentsConstValue::ClearStage != CurStage)
	{
		CurStage = UContentsConstValue::ClearStage;
		NewStage(0, CurStage);
	}

	if (true == IsDown(VK_SPACE))
	{
		Index2D where = Selector->Info->CurIndex;
		int StageN = IndexToStage(where);
		GEngine->ChangeLevel("StageLevel");
		UContentsConstValue::OpenStageNum = StageN;
	}

	StageNums;
	int a = 0;
}

int AStageSelectGameMode::IndexToStage(Index2D _index)
{
	int Result = -1;
	if (Index2D(4, 1) == _index)
	{
		Result = 1;
	} 
	else if (Index2D(4, 2) == _index)
	{
		Result = 2;
	}
	else if (Index2D(5, 1) == _index)
	{
		Result = 3;
	}
	else if (Index2D(5, 2) == _index)
	{
		Result = 4;
	}
	else if (Index2D(4, 3) == _index)
	{
		Result = 5;
	}
	else if (Index2D(6, 2) == _index)
	{
		Result = 6;
	}
	else
	{
		MsgBoxAssert("아직 안 만든 스테이지 번호");
		return -1;
	}

	return Result;
}

void AStageSelectGameMode::NewStage(int _Num1, int _Num2)
{
	Index2D StageIdx;
 	switch (_Num2)
	{
	case 1:
		StageIdx = Index2D(4, 1);
		break;
	case 2:
		StageIdx = Index2D(4, 2);
		break;
	case 3:
		StageIdx = Index2D(5, 1);
		break;
	case 4:
		StageIdx = Index2D(5, 2);
		break;
	case 5:
		StageIdx = Index2D(4, 3);
		break;
	case 6:
		StageIdx = Index2D(6, 2);
		break;
	default:
		//그만?
		StageIdx = Index2D(0, 0);
		break;
	}


	std::shared_ptr<AStageNumber> StageNum1 = GetWorld()->SpawnActor<AStageNumber>("StageNum1");
	StageNum1->SetMapScale(UContentsConstValue::StageSelectMapScale);
	StageNum1->AddActorLocation(StageNum1->CalIndexToPos(StageIdx));
	StageNum1->AddActorLocation(FVector(-6, -9));
	StageNum1->BeginPosSetting();
	StageNum1->SetActorScale3D(UContentsConstValue::TileScale * 2);
	StageNum1->SetStageNum(_Num1);

	std::shared_ptr<AStageNumber> StageNum2 = GetWorld()->SpawnActor<AStageNumber>("StageNum2");
	StageNum2->SetMapScale(UContentsConstValue::StageSelectMapScale);
	StageNum2->AddActorLocation(StageNum2->CalIndexToPos(StageIdx));
	StageNum2->AddActorLocation(FVector(6, -9));
	StageNum2->BeginPosSetting();
	StageNum2->SetActorScale3D(UContentsConstValue::TileScale * 2);
	StageNum2->SetStageNum(_Num2);

	StageNums.push_back(std::make_pair(StageNum1, StageNum2));
}

void AStageSelectGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void AStageSelectGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}