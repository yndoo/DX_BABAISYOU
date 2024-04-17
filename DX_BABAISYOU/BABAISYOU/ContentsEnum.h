#pragma once

enum class EInputDir
{
	None,
	Right,
	Left,
	Up,
	Down,
};

enum class ERenderOrder
{
	None,
	Background,
	BackTile,
	FrontTile,
};

enum class ETileType
{
	None,
	Player,
	Verb,
	Text,
	Tile,
};

// 모든 오브젝트 종류
enum class EObjectType	
{
	NONE,
	// 목적어들
	YOU,
	WIN,
	STOP,
	PUSH,
	// 동사들
	IS,
	// 주어들
	BABATEXT,
	WALLTEXT,
};

enum class EMyType
{

};