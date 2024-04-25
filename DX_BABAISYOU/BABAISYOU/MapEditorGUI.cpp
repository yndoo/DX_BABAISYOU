#include "PreCompile.h"
#include "MapEditorGUI.h"
#include <EngineCore/EngineCore.h>
#include "CreateMapGameMode.h"
#include "MapManager.h"

MapEditorGUI::MapEditorGUI()
{
	//Off();
	On();
}

MapEditorGUI::~MapEditorGUI()
{
}

void MapEditorGUI::Init()
{
	WinScale = GEngine->EngineWindow.GetWindowScale();

	Dir.MoveParent();
	Dir.Move("ContentsResources");
	Dir.Move("Save");
}

void MapEditorGUI::Tick(ULevel* _Level, float _Delta)
{
	std::string str = _Level->GetName();

	if (str._Equal("CreateMapLevel"))
	{
		On();
		if (GameMode == nullptr)
		{
			GameMode = dynamic_cast<CreateMapGameMode*>(_Level->GetGameMode().get());
		}
	}
	else
	{
		Off();
	}

	//DebugGMM();
}

void MapEditorGUI::OnGui(ULevel* _Level, float _Delta)
{
	ImGui::InputInt2(" : MapScale (Default : 864 X 648)", MapScale);

	float4 MousePos = GEngine->EngineWindow.GetScreenMousePos();
	float4 MousePosWorld = _Level->GetMainCamera()->ScreenPosToWorldPos(MousePos);
	float4 MouseIndexTest = CalPosToIndex(MousePosWorld);
	ImGui::Text(("WorldMouse : " + MousePosWorld.ToString()).c_str());
	ImGui::Text(("WorldMouseIndex : " + MouseIndexTest.ToString()).c_str());

	
	if(true == ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		// 더블 클릭한 곳 인덱스 얻어옴
		// (클릭한 곳으로 하면 다른 버튼 눌렀을 때도 들어오기 때문)
		ClickIndex = MouseIndexTest;
		int a = 0;
	}

	if (true == ImGui::Button("BABA"))
	{
		TargetType = EObjectType::BABA;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);

		// 이거 해도 당장 보이진 않는디..
		//GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}
	if (true == ImGui::Button("Flag"))
	{
		TargetType = EObjectType::FLAG;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);

		// 이거 해도 당장 보이진 않는디..
		//GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}
	
	ImGui::InputText("FileName", FileName, 25);

	if (true == ImGui::Button("Save")) 
	{
		if (TileData.empty() == true) 
		{
			return;
		}
		UEngineSerializer Ser;
		Ser << TileData;
		std::string Str = FileName;
		UEngineFile File = Dir.GetPathFromFile(Str + ".Data");
		File.Open(EIOOpenMode::Write, EIODataType::Binary);
		File.Save(Ser);
	}

	if (true == ImGui::Button("Load")) 
	{
		TileData.clear();

		UEngineSerializer Ser;
		std::string Str = FileName;
		UEngineFile File = Dir.GetPathFromFile(Str + ".Data");
		if (false == File.IsExists()) 
		{
			return;
		}
		File.Open(EIOOpenMode::Read, EIODataType::Binary);
		File.Load(Ser);
		Ser >> TileData;
	
		int Index = 0;
		while (TileData.size() > Index) 
		{
			int x = TileData[Index];
			int y = TileData[Index + 1];
			int type = TileData[Index + 2];
			//GameMode->AutoCreate(static_cast<EObjectType>(type), x, y, FVector(MapScale[0], MapScale[1]));
			Index += 3;
		}
	}
}

FVector MapEditorGUI::CalPosToIndex(FVector _Pos)
{
	FVector Index = FVector::Zero;

	// 인덱스 다같이 왼쪽 아래로 땡기려면 좌표를 오른쪽 위로 땡긴다고 생각하고 정리
	
	_Pos.X += MapScale[0] / 2;
	_Pos.Y += MapScale[1] / 2;

	Index.X = static_cast<int>(_Pos.X / UContentsConstValue::ITileX);
	Index.Y = static_cast<int>(_Pos.Y / UContentsConstValue::ITileY);


	return Index;
}

//void MapEditorGUI::DebugGMM()
//{
//	for (int y = 19; y >= 0; y--)		// 세로
//	{
//		std::string Msg = "";
//		for (int x = 0; x < 24; x++)	// 가로
//		{
//			int ss = GMapManager->Graph[x][y].size();
//
//			Msg += std::format("{} ", std::to_string(ss));
//		}
//		Msg += "\n";
//		UEngineDebugMsgWindow::PushMsg(Msg);
//	}
//}