#pragma once
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineBase/EngineDirectory.h>

#include "ContentsConstValue.h"

class CreateMapGameMode;
class MapEditorGUI : public UEngineDebugMsgWindow
{
public:
	MapEditorGUI();
	~MapEditorGUI();

	MapEditorGUI(const MapEditorGUI& _Other) = delete;
	MapEditorGUI(MapEditorGUI&& _Other) noexcept = delete;
	MapEditorGUI& operator=(const MapEditorGUI& _Other) = delete;
	MapEditorGUI& operator=(MapEditorGUI&& _Other) noexcept = delete;
protected:
	void Init() override;
	void Tick(ULevel* Level, float _Delta) override;
	void OnGui(ULevel* Level, float _Delta) override;

	CreateMapGameMode* GameMode = nullptr;
private:
	FVector CalPosToIndex(FVector _Pos);
	//void DebugGMM();

	UEngineDirectory Dir;
	FVector WinScale = FVector::Zero;
	FVector ClickIndex = FVector::Zero;
	char FileName[255] = "";
	std::vector<int> TileData;	// X, Y, ObjectNum 순서로 넣을 것.
	int MapScale[2] = { 864, 648 };
	EObjectType TargetType = EObjectType::NONE;
	int ObjectNum = -1;
};

