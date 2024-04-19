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
	// ZInput�� StackUpdate������
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

	// ��ȭ �߻� ��
	if (BeforeInputCount != UContentsConstValue::InputCount)
	{
		Update();
		BeforeInputCount = UContentsConstValue::InputCount;
	}
}

void BABAGameMode::StackUpdate()
{
	// ��� ������Ʈ ������ ��, �� ������ �� �����ؼ� Stack�� �־���� ��
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

// BABATEXT�� BABAPLAYER ��ü �̾��ִ� �Լ�
void BABAGameMode::FinalUpdate()
{
	for (AObject* sub : OnSubjects)
	{
		// PlayerType : �־� �ؽ�Ʈ�� �����ϴ� Player Ÿ��
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

// ��� ���� ���ִ� �Լ�
void BABAGameMode::ClearAllSentence()
{
	for (AObject* obj : AllObjects)
	{
		obj->SentenceON = false;
		// �׸� ������Ʈ���� ���忡 ���� ObjectiveType�� �����ǹǷ� �ʱ�ȭ�ص� ������
		if (obj->Info->TileType == ETileType::Player)
		{
			obj->Info->MyObjectiveType = EObjectType::NONE;
		}
	}
	
	OnSubjects.clear();
}

// ���� �˻��ϴ� �Լ�
void BABAGameMode::SentenceUpdate()
{
	// ��ü Clear
	ClearAllSentence();

	for (AObject* sub : Texts)
	{
		// �־� ������ ����˻�
		if (sub->Info->TileType == ETileType::Subject)
		{
			// ���� üũ, ������ üũ �� ���� ������ ����� return��.
			AObject* IsObjective = VerbCheck(sub->Info->CurIndex.X, sub->Info->CurIndex.Y);
			if (IsObjective == nullptr)
			{
				SentenceDir = -1;
				continue;
			}
			
			// ������ ������ 
			sub->SentenceON = true;
			IsObjective->SentenceON = true;
			// On�� �־�� ����Ʈ�� ����ֱ�
			OnSubjects.push_back(sub);
			// Info ���� �ٽ����ֱ�
			// (����) �־��� ������Ÿ���� �ƴ�!!
			sub->Info->TextObjective = IsObjective->Info->MyType;
		}
	}
}

AObject* BABAGameMode::VerbCheck(int _X, int _Y/*�־��� �ε���*/)
{
	// ���鼭 ���� ã��
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
				// ����
				SentenceDir = i;

				// ������ üũ
				AObject* IsObjective = ObjectiveCheck(nx, ny);
				if (IsObjective == nullptr)
				{
					SentenceDir = -1;
					return nullptr;
				}

				// ���� ON
				Obj->SentenceON = true;

				return IsObjective;
			}
		}
	}
	return nullptr;
}

AObject* BABAGameMode::ObjectiveCheck(int _X, int _Y/*������ �ε���*/)
{
	// SentenceDir �������� ������ ã��
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
			// ����
			return Obj;
		}
	}
	
	return nullptr;
}

void BABAGameMode::DebugGMM()
{
	for (int y = 19; y >= 0; y--)		// ����
	{
		std::string Msg = "";
		for (int x = 0; x < 40; x++)	// ����
		{
			int ss = GMapManager->Graph[x][y].size();

			Msg += std::format("{} ", std::to_string(ss));
		}
		Msg += "\n";
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}