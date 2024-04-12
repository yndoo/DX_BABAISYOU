#pragma once
#include "Object.h"

class MapManager
{
	friend AGameMode;
public:
	MapManager();
	~MapManager();

	MapManager(const MapManager& _Other) = delete;
	MapManager(MapManager&& _Other) noexcept = delete;
	MapManager& operator=(const MapManager& _Other) = delete;
	MapManager& operator=(MapManager&& _Other) noexcept = delete;

	std::list<std::shared_ptr<AObject>>* GetObjectList(int i, int j)
	{
		return &Graph[i][j];
	}

	void SetObject(std::shared_ptr<AObject> _Obj, int _x, int _y)
	{
		Graph[_x][_y].push_back(_Obj);
	}

	//void ClearGraph();
protected:

private:
	static std::list<std::shared_ptr<AObject>> Graph[40][20];	//[가로][세로] list 2차원 배열

};

