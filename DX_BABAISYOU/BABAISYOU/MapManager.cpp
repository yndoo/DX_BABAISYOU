#include "PreCompile.h"
#include "MapManager.h"


std::list<AObject*> MapManager::Graph[40][20] = {};
MapManager* GMapManager = nullptr;

MapManager::MapManager()
{
	GMapManager = this;
}

MapManager::~MapManager()
{
}
