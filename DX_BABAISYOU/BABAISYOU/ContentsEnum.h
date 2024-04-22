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
	// ������, �Ӽ��� (������ TEXT)
	YOU,
	PUSH,
	STOP,
	WIN,
	DEFEAT,
	SINK,
	FLOAT,
	// �����
	IS,
	// �־��
	BABATEXT,
	WALLTEXT,
	FLAGTEXT,
	WATERTEXT,
	ROCKTEXT,
};

enum class EMyType
{

};