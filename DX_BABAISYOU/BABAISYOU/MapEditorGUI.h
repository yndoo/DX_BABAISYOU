#pragma once
#include <EngineCore/EngineEditorWindow.h>

class MapEditorGUI : public UEngineEditorWindow
{
public:
	MapEditorGUI();
	~MapEditorGUI();

	MapEditorGUI(const MapEditorGUI& _Other) = delete;
	MapEditorGUI(MapEditorGUI&& _Other) noexcept = delete;
	MapEditorGUI& operator=(const MapEditorGUI& _Other) = delete;
	MapEditorGUI& operator=(MapEditorGUI&& _Other) noexcept = delete;
protected:

private:

};

