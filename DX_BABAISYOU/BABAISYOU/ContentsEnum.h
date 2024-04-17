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

// �ΰ��ӿ��� ���� ĥ�����ִ� �ؽ�Ʈ �׸� Ÿ�ϵ�(�������)
enum class EObjectiveType	
{
	NONE,
	YOU,
	WIN,
	STOP,
	PUSH,

};