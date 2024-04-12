#pragma once
#include "Object.h"

class MapManager
{
public:
	MapManager();
	~MapManager();

	MapManager(const MapManager& _Other) = delete;
	MapManager(MapManager&& _Other) noexcept = delete;
	MapManager& operator=(const MapManager& _Other) = delete;
	MapManager& operator=(MapManager&& _Other) noexcept = delete;

	AObject* GetObject(int i, int j)
	{
		return Graph[i][j];
	}
protected:

private:
	static AObject* Graph[40][20];	//[가로][세로]
};

