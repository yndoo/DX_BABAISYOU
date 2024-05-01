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

	MapScale[0] = UContentsConstValue::Stage5MapScale.iX();
	MapScale[1] = UContentsConstValue::Stage5MapScale.iY();
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
		MapScale;
		int a = 0;
	}
	ImGui::Text("\n== TileObject ==");
	if (true == ImGui::Button("Grass"))
	{
		TargetType = EObjectType::GRASS;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("Wall"))
	{
		TargetType = EObjectType::WALL;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("Water"))
	{
		TargetType = EObjectType::WATER;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("Lava"))
	{
		TargetType = EObjectType::LAVA;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}

	ImGui::Text("== PlayerObject ==");
	if (true == ImGui::Button("BABA"))
	{
		TargetType = EObjectType::BABA;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("Flag"))
	{
		TargetType = EObjectType::FLAG;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("Rock"))
	{
		TargetType = EObjectType::ROCK;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("Skull"))
	{
		TargetType = EObjectType::SKULL;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}
	if (true == ImGui::Button("Tile"))
	{
		TargetType = EObjectType::TILE;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}

	ImGui::Text("== TextObject ==");
	ImGui::Text("Subject");
	if (true == ImGui::Button("BabaText"))
	{
		TargetType = EObjectType::BABATEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("FlagText"))
	{
		TargetType = EObjectType::FLAGTEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("LavaText"))
	{
		TargetType = EObjectType::LAVATEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("RockText"))
	{
		TargetType = EObjectType::ROCKTEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("SkullText"))
	{
		TargetType = EObjectType::SKULLTEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("WallText"))
	{
		TargetType = EObjectType::WALLTEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("WaterText"))
	{
		TargetType = EObjectType::WATERTEXT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}

	ImGui::Text("Verb");
	if (true == ImGui::Button("IsText"))
	{
		TargetType = EObjectType::IS;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}
	ImGui::Text("Objective");
	if (true == ImGui::Button("YouText"))
	{
		TargetType = EObjectType::YOU;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("DefeatText"))
	{
		TargetType = EObjectType::DEFEAT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("StopText"))
	{
		TargetType = EObjectType::STOP;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("WinText"))
	{
		TargetType = EObjectType::WIN;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("HotText"))
	{
		TargetType = EObjectType::HOT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("MeltText"))
	{
		TargetType = EObjectType::MELT;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("PushText"))
	{
		TargetType = EObjectType::PUSH;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}ImGui::SameLine();
	if (true == ImGui::Button("SinkText"))
	{
		TargetType = EObjectType::SINK;
		ObjectNum = static_cast<int>(TargetType);
		TileData.push_back(ClickIndex.iX());
		TileData.push_back(ClickIndex.iY());
		TileData.push_back(ObjectNum);
		GameMode->AutoCreate(TargetType, ClickIndex.iX(), ClickIndex.iY(), FVector(MapScale[0], MapScale[1]));
	}

	ImGui::Text("\n== One Time Cancel ==");
	if (true == ImGui::Button("Cancel"))
	{
		TileData.pop_back();
		TileData.pop_back();
		TileData.pop_back();
	}

	ImGui::Text("\n\n== Save File ==");
	ImGui::InputText("Save FileName", FileName, 25);

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

	ImGui::Text("== Load File ==");
	ImGui::InputText("Load FileName", FileName, 25);
	if (true == ImGui::Button("Load"))
	{
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

		GMapManager->ClearGraph();
		int Index = 0;
		while (TileData.size() > Index)
		{
			int x = TileData[Index];
			int y = TileData[Index + 1];
			int type = TileData[Index + 2];
			GameMode->AutoCreate(static_cast<EObjectType>(type), x, y, UContentsConstValue::Stage1MapScale);
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
