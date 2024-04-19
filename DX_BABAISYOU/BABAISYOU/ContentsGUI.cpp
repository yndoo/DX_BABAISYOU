#include "PreCompile.h"
#include "ContentsGUI.h"
#include <EngineCore/EngineCore.h>

ContentsGUI::ContentsGUI()
{
}

ContentsGUI::~ContentsGUI()
{
}

void ContentsGUI::Init()
{
}

void ContentsGUI::OnGui(ULevel* _Level, float _Delta)
{
	if (true == ImGui::Button("Stage1Level"))
	{
		GEngine->ChangeLevel("Stage1Level");
	}

	if (true == ImGui::Button("SelectMapLevel"))
	{
		GEngine->ChangeLevel("SelectMapLevel");
	}

	/*if (true == ImGui::Button("CreateMapLevel"))
	{
		GEngine->ChangeLevel("CreateMapLevel");
	}*/
}