#include "PreCompile.h"
#include "BABAISYOUCore.h"
#include "PlayGameMode.h"
#include <EngineCore/EngineSprite.h>
#include "Stage1GameMode.h"
#include "StageSelectGameMode.h"

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

		UEngineSprite::CreateCutting("CuttingTest.png", 4, 3);

		UEngineSprite::CreateCutting("BABA.png", 17, 3);
		UEngineSprite::CreateCutting("WALL.png", 18, 3);
		UEngineSprite::CreateCutting("IS.png", 2, 3);

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


	//GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->CreateLevel<AStage1GameMode>("Stage1Level");
	GEngine->CreateLevel<AStageSelectGameMode>("SelectMapLevel");
	GEngine->ChangeLevel("SelectMapLevel");
	int a = 0;
}