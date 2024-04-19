#pragma once
#include <EngineCore/EngineEditorWindow.h>
#include <EngineBase/EngineDirectory.h>

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
	virtual void Init();
	virtual void Tick(ULevel* _Level, float _Delta);
	virtual void OnGui(ULevel* _Level, float _Delta);

private:

};

