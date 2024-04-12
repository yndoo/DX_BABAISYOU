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

enum class EObjectType
{
	None,
	Text,
	Tile,
};

enum class EMapObjects
{
	NONE,
	BABA,
	WALL,
};