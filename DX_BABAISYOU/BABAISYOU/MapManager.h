#pragma once
#include "Object.h"
#include  "LerpMoveObject.h"

class MapManager
{
	friend AGameMode;
	friend ALerpMoveObject;

public:
	MapManager();
	~MapManager();

	MapManager(const MapManager& _Other) = delete;
	MapManager(MapManager&& _Other) noexcept = delete;
	MapManager& operator=(const MapManager& _Other) = delete;
	MapManager& operator=(MapManager&& _Other) noexcept = delete;

	std::list<AObject*>* GetObjectList(int i, int j)
	{
		return &Graph[i][j];
	}

	void SetObject(AObject* _Obj, int _x, int _y)
	{
		Graph[_x][_y].push_back(_Obj);
	}

	//void ClearGraph();
	static std::list<AObject*> Graph[40][20];	//[����][����] list 2���� �迭

protected:

private:

};

extern MapManager* GMapManager;