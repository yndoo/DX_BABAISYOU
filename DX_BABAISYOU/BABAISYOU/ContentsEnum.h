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

	// 얘네는 다 PUSH 가능해야 함
	Subject,	//주어
	Verb,		//동사	
	Objective,	//목적어
	
	Tile,		//보류
};

// 모든 오브젝트 종류
enum class EObjectType	
{
	NONE,
	// 그림들
	BABA,
	WALL,
	FLAG,
	// 목적어들 (무조건 TEXT)
	YOU,
	WIN,
	STOP,
	PUSH,
	// 동사들
	IS,
	// 주어들
	BABATEXT,
	WALLTEXT,
	FLAGTEXT,
};

enum class EMyType
{

};