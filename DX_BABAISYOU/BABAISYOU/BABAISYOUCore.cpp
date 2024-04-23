#include "PreCompile.h"
#include "BABAISYOUCore.h"
#include "PlayGameMode.h"
#include <EngineCore/EngineSprite.h>
#include "Stage1GameMode.h"
#include "StageSelectGameMode.h"
#include "CreateMapGameMode.h"

#include <EngineCore/EngineEditorGUI.h>
#include "ContentsGUI.h"
#include "MapEditorGUI.h"

UBABAISYOUCore::UBABAISYOUCore() 
{
}

UBABAISYOUCore::~UBABAISYOUCore() 
{
}

void UBABAISYOUCore::Initialize()
{
	{
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}

		/*std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}*/

		// Player Objects
		UEngineSprite::CreateCutting("BABA.png", 17, 3);
		UEngineSprite::CreateCutting("WALL.png", 18, 3);
		UEngineSprite::CreateCutting("WATER.png", 18, 3);
		UEngineSprite::CreateCutting("FLAG.png", 2, 3);
		UEngineSprite::CreateCutting("ROCK.png", 1, 3);
		UEngineSprite::CreateCutting("SKULL.png", 4, 3);

		// TEXT Objects
		UEngineSprite::CreateCutting("BABAText.png", 2, 3);
		UEngineSprite::CreateCutting("FLAGText.png", 3, 3);
		UEngineSprite::CreateCutting("ROCkText.png", 2, 3);
		UEngineSprite::CreateCutting("SKULLText.png", 2, 3);

		UEngineSprite::CreateCutting("IS.png", 2, 3);

		UEngineSprite::CreateCutting("YOU.png", 3, 3);
		UEngineSprite::CreateCutting("STOP.png", 3, 3);
		UEngineSprite::CreateCutting("WIN.png", 3, 3);
		UEngineSprite::CreateCutting("DEFEAT.png", 3, 3);
		UEngineSprite::CreateCutting("SINK.png", 3, 3);
		UEngineSprite::CreateCutting("PUSH.png", 3, 3);

		// ETC
		UEngineSprite::CreateCutting("SelectMap_background.png", 3, 1);
		UEngineSprite::CreateCutting("Selector.png", 3, 1);
		
	}


	{
		//UEngineDirectory Dir;
		//Dir.MoveToSearchChild("ContentsResources");
		//Dir.Move("Sound");
		//std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
		//for (UEngineFile& File : Files)
		//{
		//	UEngineSound::Load(File.GetFullPath());
		//}
	}

	// GUI
	UEngineEditorGUI::CreateEditorWindow<ContentsGUI>("Contents");
	UEngineEditorGUI::CreateEditorWindow<MapEditorGUI>("MapEditor");

	// Level
	//GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->CreateLevel<AStage1GameMode>("Stage1Level");
	GEngine->CreateLevel<AStageSelectGameMode>("SelectMapLevel");
	GEngine->CreateLevel<CreateMapGameMode>("CreateMapLevel");
	GEngine->ChangeLevel("Stage1Level");

	int a = 0;
}