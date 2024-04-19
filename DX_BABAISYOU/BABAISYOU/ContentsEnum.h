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
	// ������� (������ TEXT)
	YOU,
	WIN,
	STOP,
	PUSH,
	// �����
	IS,
	// �־��
	BABATEXT,
	WALLTEXT,
	FLAGTEXT,
};

enum class EMyType
{

};