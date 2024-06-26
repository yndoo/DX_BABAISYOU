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
	Foot,
	UI,
	Cover,
};

enum class ETileType
{
	None,
	Player,

	// 얘네는 다 PUSH 가능해야 함
	Subject,	//주어
	Verb,		//동사	
	Objective,	//목적어
	
	Tile,		//타일객체
};

// 모든 오브젝트 종류
enum class EObjectType	
{
	NONE,
	// 그림들
	BABA,
	WALL,
	FLAG,
	WATER,
	ROCK,
	SKULL, 
	LAVA,
	GRASS,
	// 목적어, 속성들 (무조건 TEXT)
	YOU,
	PUSH,
	STOP,
	WIN,
	DEFEAT,
	SINK,
	FLOAT,
	HOT,
	
	// 동사들
	IS,
	// 주어들
	BABATEXT,
	WALLTEXT,
	FLAGTEXT,
	WATERTEXT,
	ROCKTEXT,
	SKULLTEXT,
	LAVATEXT,
	GRASSTEXT,	// 필요가 딱히 없어서 아직 안 만듦.

	// 나중에 만들어진 애들은 뒤로 빼야 안 꼬임 ㅇㅅㅇ..
	// 바닥에 깔리는 애
	TILE,
	MELT,
	LINE,
};

// 게임 진행 상황
enum class EGameState
{
	NONE,
	LOBBY,
	STAGE,
	CLEAR,
	FAIL,
	CLEARMSG,
	SELECTMAP,
};