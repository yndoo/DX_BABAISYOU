#include "PreCompile.h"
#include "BABAGameMode.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include "ContentsConstValue.h"

BABAGameMode::BABAGameMode()
{
}

BABAGameMode::~BABAGameMode()
{
}

void BABAGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void BABAGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	// 변화 발생 시
	if (BeforeInputCount != UContentsConstValue::InputCount)
	{
		StackUpdate();
		SentenceUpdate();
		GameUpdate();

		BeforeInputCount = UContentsConstValue::InputCount;
	}
}

void BABAGameMode::StackUpdate()
{
	// 모든 오브젝트 움직인 애, 안 움직인 애 구분해서 Stack에 넣어줘야 함
	for (auto Obj : AllObjects)
	{
		if (Obj->EachMoveCheck_ForStack == true)
		{
			Obj->PushTrueHistory();
		}
		else
		{
			Obj->PushFalseHistory();
		}
	}
}

// BABATEXT와 BABAPLAYER 객체 이어주는 함수
void BABAGameMode::GameUpdate()
{
	for (AObject* sub : OnSubjects)
	{
		EObjectType PlayerType = UContentsConstValue::TextToPlayer[sub->Info->MyType];
		
		for (AObject* player : Players)
		{
			if (player->Info->MyType == PlayerType)
			{
				player->Info->ObjectiveType = sub->Info->ObjectiveType;
				int a = 0;
			}
		}
	}
}

// 모든 문장 꺼주는 함수
void BABAGameMode::ClearAllSentence()
{
	for (AObject* obj : AllObjects)
	{
		obj->SentenceON = false;
	}
	OnSubjects.clear();
}

// 문장 검사하는 함수
void BABAGameMode::SentenceUpdate()
{
	// 전체 Clear
	ClearAllSentence();

	for (AObject* obj : AllObjects)
	{
		// 주어 만나면 문장검사
		if (obj->Info->TileType == ETileType::Subject)
		{
			// 동사 체크, 목적어 체크 후 문장 맞으면 목적어를 return함.
			AObject* IsObjective = VerbCheck(obj->Info->CurIndex.X, obj->Info->CurIndex.Y);
			if (IsObjective == nullptr)
			{
				SentenceDir = -1;
				return;
			}
			
			// 문장이 맞으면 
			obj->SentenceON = true;
			IsObjective->SentenceON = true;
			// On된 주어들 리스트에 모아주기
			OnSubjects.push_back(obj);
			// Info 세팅 다시해주기
			obj->Info->ObjectiveType = IsObjective->Info->MyType;
		}
	}
}

AObject* BABAGameMode::VerbCheck(int _X, int _Y/*주어의 인덱스*/)
{
	// 돌면서 동사 찾기
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + _X;
		int ny = dy[i] + _Y;
		if (nx < 0 || ny < 0 || nx > UContentsConstValue::MaxIndexX || ny > UContentsConstValue::MaxIndexY)
		{
			continue;
		}
		for (AObject* Obj : GMapManager->Graph[nx][ny])
		{
			if (Obj->Info->TileType == ETileType::Verb)
			{
				// 방향
				SentenceDir = i;

				// 목적어 체크
				AObject* IsObjective = ObjectiveCheck(nx, ny);
				if (IsObjective == nullptr)
				{
					SentenceDir = -1;
					return nullptr;
				}

				// 동사 ON
				Obj->SentenceON = true;

				// 문장이 맞으면 Info 세팅 다시해주기
				// 목적어 여러개면 어캐되는거냐? 해봤자 두갠가? 일단 보류? 제일 나중꺼 하나 걸리게 해두자


				return IsObjective;
			}
		}
	}
	return nullptr;
}

AObject* BABAGameMode::ObjectiveCheck(int _X, int _Y/*동사의 인덱스*/)
{
	// SentenceDir 방향으로 목적어 찾기
	int i = SentenceDir;
	int nx = dx[i] + _X;
	int ny = dy[i] + _Y;
	if (nx < 0 || ny < 0 || nx > UContentsConstValue::MaxIndexX || ny > UContentsConstValue::MaxIndexY)
	{
		return nullptr;
	}
	for (AObject* Obj : GMapManager->Graph[nx][ny])
	{
		if (Obj->Info->TileType == ETileType::Objective)
		{
			// 방향
			return Obj;
		}
	}
	
	return nullptr;
}

void BABAGameMode::DebugGMM()
{
	for (int y = 19; y >= 0; y--)		// 세로
	{
		std::string Msg = "";
		for (int x = 0; x < 40; x++)	// 가로
		{
			int ss = GMapManager->Graph[x][y].size();

			Msg += std::format("{} ", std::to_string(ss));
		}
		Msg += "\n";
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}