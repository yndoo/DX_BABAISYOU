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

void BABAGameMode::Update()
{
	// ZInput면 StackUpdate하지마
	if (true == UContentsConstValue::ZInput)
	{
		SentenceUpdate();
		FinalUpdate();
		UContentsConstValue::ZInput = false;
		return;
	}
	else
	{
		StackUpdate();
		SentenceUpdate();
		FinalUpdate();
	}
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
		Update();
		BeforeInputCount = UContentsConstValue::InputCount;
	}
}

void BABAGameMode::StackUpdate()
{
	// 모든 오브젝트 움직인 애, 안 움직인 애 구분해서 Stack에 넣어줘야 함
	for (auto Obj : AllObjects)
	{
		if (true == Obj->EachMoveCheck_ForStack)
		{
			Obj->PushTrueHistory();
		}
		else if (false == Obj->EachMoveCheck_ForStack)
		{
			if (Obj->Info->MyType == EObjectType::BABATEXT)
			{
				int a = 0;
			}
 			Obj->PushFalseHistory();
		}
	}
}

// BABATEXT와 BABAPLAYER 객체 이어주는 함수
void BABAGameMode::FinalUpdate()
{
	for (AObject* sub : OnSubjects)
	{
		// PlayerType : 주어 텍스트에 대응하는 Player 타입
		EObjectType PlayerType = UContentsConstValue::TextToPlayer[sub->Info->MyType];
		
		for (AObject* player : Players)
		{
			if (player->Info->MyType == PlayerType)
			{
				player->Info->MyObjectiveType = sub->Info->TextObjective;
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
		// 그림 오브젝트들은 문장에 의해 ObjectiveType이 결정되므로 초기화해도 괜찮음
		if (obj->Info->TileType == ETileType::Player)
		{
			obj->Info->MyObjectiveType = EObjectType::NONE;
		}
	}
	
	OnSubjects.clear();
}

// 문장 검사하는 함수
void BABAGameMode::SentenceUpdate()
{
	// 전체 Clear
	ClearAllSentence();

	for (AObject* sub : Texts)
	{
		// 주어 만나면 문장검사
		if (sub->Info->TileType == ETileType::Subject)
		{
			// 동사 체크, 목적어 체크 후 문장 맞으면 목적어를 return함.
			AObject* IsObjective = VerbCheck(sub->Info->CurIndex.X, sub->Info->CurIndex.Y);
			if (IsObjective == nullptr)
			{
				SentenceDir = -1;
				continue;
			}
			
			// 문장이 맞으면 
			sub->SentenceON = true;
			IsObjective->SentenceON = true;
			// On된 주어들 리스트에 모아주기
			OnSubjects.push_back(sub);
			// Info 세팅 다시해주기
			// (주의) 주어의 목적어타입이 아님!!
			sub->Info->TextObjective = IsObjective->Info->MyType;
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