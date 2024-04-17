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

// ��� ������Ʈ ����
enum class EObjectType	
{
	NONE,
	// �������
	YOU,
	WIN,
	STOP,
	PUSH,
	// �����
	IS,
	// �־��
	BABATEXT,
	WALLTEXT,
};

enum class EMyType
{

};