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
	Text,
	Player,
	Cover,
};

enum class ETileType
{
	None,
	Player,

	// ��״� �� PUSH �����ؾ� ��
	Subject,	//�־�
	Verb,		//����	
	Objective,	//������
	
	Tile,		//����
};

// ��� ������Ʈ ����
enum class EObjectType	
{
	NONE,
	// �׸���
	BABA,
	WALL,
	FLAG,
	WATER,
	ROCK,
	SKULL, 
	LAVA,
	GRASS,
	// ������, �Ӽ��� (������ TEXT)
	YOU,
	PUSH,
	STOP,
	WIN,
	DEFEAT,
	SINK,
	FLOAT,
	HOT,
	// �����
	IS,
	// �־��
	BABATEXT,
	WALLTEXT,
	FLAGTEXT,
	WATERTEXT,
	ROCKTEXT,
	SKULLTEXT,
	LAVATEXT,
	GRASSTEXT,	// �ʿ䰡 ���� ��� ���� �� ����.
};

enum class EMyType
{

};