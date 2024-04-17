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

enum class EMapObjects
{
	NONE,
	BABA,
	WALL,
};

// 인게임에서 배경색 칠해져있는 텍스트 네모 타일들(목적어들)
enum class EObjectiveType	
{
	NONE,
	YOU,
	WIN,
	STOP,
	PUSH,

};