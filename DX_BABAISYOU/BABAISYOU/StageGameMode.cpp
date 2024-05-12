#include "PreCompile.h"
#include "StageGameMode.h"
#include "ContentsConstValue.h"

AStageGameMode::AStageGameMode()
{
}

AStageGameMode::~AStageGameMode()
{
}

void AStageGameMode::BeginPlay()
{
	Super::BeginPlay();

}

void AStageGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AStageGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	BGMPlayer = UEngineSound::SoundPlay("StageBGM.mp3");
	BGMPlayer.SetVolume(0.3f);
	BGMPlayer.Loop(100);

	Back = GetWorld()->SpawnActor<ABackground>("background");
	Back->SetActorLocation({ 0, 0, 400 });
	Back->SetOrder(ERenderOrder::Background);
	Back->BGImageSetting();

	//UContentsConstValue::OpenStageNum = 8;
	switch (UContentsConstValue::OpenStageNum)
	{
	case 0:
		Back->SetActorScale3D(UContentsConstValue::Stage0MapScale);
		CurMapScale = UContentsConstValue::Stage0MapScale;
		break;
	case 1:
	case 2:
		Back->SetActorScale3D(UContentsConstValue::Stage1MapScale);
		CurMapScale = UContentsConstValue::Stage1MapScale;
		break;
	case 3:
		Back->SetActorScale3D(UContentsConstValue::Stage3MapScale);
		CurMapScale = UContentsConstValue::Stage3MapScale;
		break;
	case 4:
	case 6:	
	case 7:
		Back->SetActorScale3D(UContentsConstValue::Stage4MapScale);	// 24 X 14
		CurMapScale = UContentsConstValue::Stage4MapScale;
		break;
	case 5:
		Back->SetActorScale3D(UContentsConstValue::Stage5MapScale);
		CurMapScale = UContentsConstValue::Stage5MapScale;
		break;
	case 8:
		Back->SetActorScale3D(UContentsConstValue::Stage8MapScale);
		CurMapScale = UContentsConstValue::Stage8MapScale;
		UContentsConstValue::ITileX = 72;
		UContentsConstValue::ITileY = 72;
		LoadMapFile("Stage8");
		for (AObject* obj : AllObjects)
		{
			obj->SetRootScale(FVector(108, 108));
		}
		Update();
		return;
	default:
		break;
	}


	LoadMapFile("Stage"+std::to_string(UContentsConstValue::OpenStageNum));

	Update();
}

void AStageGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	
	BGMPlayer.Off();
	Back.get()->SetActive(false);
}
