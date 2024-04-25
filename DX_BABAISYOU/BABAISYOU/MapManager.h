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

	void ClearGraph()
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				Graph[i][j].clear();
			}
		}
	}

	//void ClearGraph();
	static std::list<AObject*> Graph[40][20];	//[가로][세로] list 2차원 배열

protected:

private:

};

extern MapManager* GMapManager;