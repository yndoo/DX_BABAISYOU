#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include <EngineCore/Camera.h>
#include <EngineCore/EngineCore.h>
#include <EngineCore/Image.h>
#include "Background.h"
#include "ContentsEnum.h"
#include "ContentsConstValue.h"
#include "Object.h"
#include "MapManager.h"
#include "Bridge.h"

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

	CurMapScale = UContentsConstValue::StageSelectMapScale;
	StageNums.resize(10);
	UI->KeyUIOff();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	Selector = GetWorld()->SpawnActor<AStageSelector>("Selector");
	Selector->SetMapScale(UContentsConstValue::StageSelectMapScale);
	Selector->AddActorLocation(Selector->CalIndexToPos(Index2D(3, 1)));
	Selector->BeginPosSetting();
	Selector->SetActorScale3D(UContentsConstValue::TileScale * 1.5);
	Selector->SetOrder(ERenderOrder::UI);
	//AllObjects.push_back(Selector.get());

	std::shared_ptr<ABackground> Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorScale3D(UContentsConstValue::StageSelectMapImgScale);
	Back->SetActorLocation({ 0, 0, 400 });
	Back->SelectStageSetting();
	Back->SetOrder(ERenderOrder::Background);

	CurStage = UContentsConstValue::ClearStage;
	NewStage(0, 0);
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	//Super::Tick(_DeltaTime);

	if (BeforeInputCount != UContentsConstValue::InputCount)
	{
		UEngineSound::SoundPlay("Move.ogg");
		BeforeInputCount = UContentsConstValue::InputCount;
	}
	 
	if (UContentsConstValue::ClearStage != CurStage)
	{
		CurStage = UContentsConstValue::ClearStage;

		if (true == UContentsConstValue::StageCleared[UContentsConstValue::ClearStage - 1])
		{
			StageNums[UContentsConstValue::ClearStage - 1].first->SetRendererMulColor(FVector(237, 226, 133));
			StageNums[UContentsConstValue::ClearStage - 1].second->SetRendererMulColor(FVector(237, 226, 133));
		}

		switch (CurStage)
		{
		case 1:
			NewStage(0, 1);
			break;
		case 2:
			NewStage(0, 2);
			NewStage(0, 3);
			break;
		case 3:
			NewStage(0, 4);
			NewStage(0, 5);
			break;
		case 4:
			NewStage(0, 4);
			break;
		case 5:
			NewStage(0, 6);
			NewStage(0, 7);
			break;
		case 6:
			NewStage(0, 7);
			break;
		case 8:
			NewStage(0, 5);
			NewStage(0, 8);
			break;
		default:
			break;
		}
		//NewStage(0, CurStage);
	}

	if (true == IsDown(VK_SPACE))
	{
		UEngineSound::SoundPlay("StageEnterSound.ogg");
		Index2D where = Selector->Info->CurIndex;
		int StageN = IndexToStage(where);
		UContentsConstValue::OpenStageNum = StageN;
		GEngine->ChangeLevel("ChangingLevel");
		//GEngine->ChangeLevel("StageLevel");
	}
}

int AStageSelectGameMode::IndexToStage(Index2D _index)
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

void AStageSelectGameMode::NewStage(int _Num1, int _Num2)
{
	Index2D StageIdx;

 	switch (_Num2)
	{
	case 0:
		StageIdx = Index2D(3, 1);
		break;
	case 1:
		StageIdx = Index2D(4, 3);
		break;
	case 2:
		StageIdx = Index2D(4, 4);
		break;
	case 3:
		StageIdx = Index2D(5, 3);
		break;
	case 4:
		StageIdx = Index2D(5, 4);
		break;
	case 5:
		StageIdx = Index2D(4, 5);
		break;
	case 6:
		StageIdx = Index2D(6, 4);
		break;
	case 7:
		StageIdx = Index2D(5, 5);
		break;
	case 8:
		{
			StageIdx = Index2D(11, 8);
		}
		break;
	default:
		//그만?
		StageIdx = Index2D(0, 0);
		break;
	}
	if (true == UContentsConstValue::MadeStages[_Num2])
	{
		return;
	}
	UContentsConstValue::MadeStages[_Num2] = true;

	std::shared_ptr<AStageNumber> StageNum1 = GetWorld()->SpawnActor<AStageNumber>("StageNum1");
	StageNum1->SetMapScale(UContentsConstValue::StageSelectMapScale);
	StageNum1->AddActorLocation(StageNum1->CalIndexToPos(StageIdx));
	StageNum1->AddActorLocation(FVector(-6, -10));
	StageNum1->BeginPosSetting();
	StageNum1->SetActorScale3D(UContentsConstValue::TileScale * 2);
	StageNum1->SetStageNum(_Num1);

	std::shared_ptr<AStageNumber> StageNum2 = GetWorld()->SpawnActor<AStageNumber>("StageNum2");
	StageNum2->SetMapScale(UContentsConstValue::StageSelectMapScale);
	StageNum2->AddActorLocation(StageNum2->CalIndexToPos(StageIdx));
	StageNum2->AddActorLocation(FVector(6, -10));
	StageNum2->BeginPosSetting();
	StageNum2->SetActorScale3D(UContentsConstValue::TileScale * 2);
	StageNum2->SetStageNum(_Num2);

	StageNums[_Num2] = std::make_pair(StageNum1, StageNum2);
}

void AStageSelectGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	BGMPlayer = UEngineSound::SoundPlay("SelectMapBGM.mp3");
	BGMPlayer.SetVolume(0.3f);
	BGMPlayer.Loop(100);

	int MaxClearedStage = -1;
	for(int i = 9; i>=0; i--)
	{
		if (true == UContentsConstValue::StageCleared[i])
		{
			MaxClearedStage = i;
			break;
		}
	}

	if (MaxClearedStage >= 0)
	{
		AutoCreate(EObjectType::LINE, 3, 1, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 4, 1, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 4, 2, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 4, 3, UContentsConstValue::StageSelectMapScale);
	}

	if (MaxClearedStage >= 4)
	{
		AutoCreate(EObjectType::LINE, 5, 3, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 6, 3, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 6, 4, UContentsConstValue::StageSelectMapScale);
	}

	if (MaxClearedStage >= 7)
	{
		AutoCreate(EObjectType::LINE, 5, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 6, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 7, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 8, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 9, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 10, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 11, 5, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 11, 6, UContentsConstValue::StageSelectMapScale);
		AutoCreate(EObjectType::LINE, 11, 7, UContentsConstValue::StageSelectMapScale);
	}

	if (UContentsConstValue::ClearStage == 9)
	{
		// 게임 아예 끝
		BGMPlayer.Off();
		GEngine->ChangeLevel("EndingLevel");
	}
}

void AStageSelectGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}