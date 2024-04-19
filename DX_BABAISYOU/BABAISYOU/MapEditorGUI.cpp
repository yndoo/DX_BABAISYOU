#include "PreCompile.h"
#include "MapEditorGUI.h"
#include <EngineCore/EngineCore.h>


MapEditorGUI::MapEditorGUI()
{
}

MapEditorGUI::~MapEditorGUI()
{
}

void MapEditorGUI::Init()
{
	//Dir.MoveToSearchChild("Resources");
	//Dir.Move("Save");
}

void MapEditorGUI::Tick(ULevel* _Level, float _Delta)
{

}

void MapEditorGUI::OnGui(ULevel* _Level, float _Delta)
{
	//std::shared_ptr<AGameMode> Mode = _Level->GetGameMode();
	//ATileMapMode* Ptr = dynamic_cast<ATileMapMode*>(Mode.get());
	//if (nullptr == Ptr)
	//{
	//	return;
	//}
	//UTileRenderer* TileRenderer = Ptr->TileMap->TileRenderer;

	float4 MousePos = GEngine->EngineWindow.GetScreenMousePos();
	float4 MousePosWorld = _Level->GetMainCamera()->ScreenPosToWorldPos(MousePos);

	ImGui::Text(("WorldMouse : " + MousePosWorld.ToString()).c_str());
	//float4 Index = TileRenderer->ConvertTileIndex(MousePosWorld);
	//ImGui::Text(("TileIndexPos : " + Index.ToString()).c_str());
	//ImGui::Text(std::format("Index : {} {}", Index.iX(), Index.iY()).c_str());

}