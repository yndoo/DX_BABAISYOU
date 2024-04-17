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

	// ��ȭ �߻� ��
	if (BeforeInputCount != UContentsConstValue::InputCount)
	{
		StackUpdate();
		// ����˻�
		SentenceUpdate();

		BeforeInputCount = UContentsConstValue::InputCount;
	}
}

void BABAGameMode::StackUpdate()
{
	// ��� ������Ʈ ������ ��, �� ������ �� �����ؼ� Stack�� �־���� ��
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

void BABAGameMode::SentenceUpdate()
{
	for (AObject* obj : AllObjects)
	{
		// �־� ������ ����˻�
		if (obj->Info->TileType == ETileType::Subject)
		{
			// ���� üũ, ������ üũ �� ���� ������ ����� return��.
			AObject* IsObjective = VerbCheck(obj->Info->CurIndex.X, obj->Info->CurIndex.Y);
			if (IsObjective == nullptr)
			{
				SentenceDir = -1;
				return;
			}
			
			// ������ ������ Info ���� �ٽ����ֱ�
			obj->Info->ObjectiveType = IsObjective->Info->MyType;
		}
	}
}

AObject* BABAGameMode::VerbCheck(int _X, int _Y/*�־��� �ε���*/)
{
	// ���鼭 ���� ã��
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + _X;
		int ny = dx[i] + _Y;
		if (nx<0 || ny<0 || nx>UContentsConstValue::MaxIndexX || ny>UContentsConstValue::MaxIndexY)
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
				AObject* IsObjective = ObjectiveCheck(_X, _Y);
				if (IsObjective == nullptr)
				{
					SentenceDir = -1;
					return nullptr;
				}

				// ���� ON .. ��ĳ����
				Obj->SentenceON = true;

				// ������ ������ Info ���� �ٽ����ֱ�
				// ������ �������� ��ĳ�Ǵ°ų�? �غ��� �ΰ���? �ϴ� ����? ���� ���߲� �ϳ� �ɸ��� �ص���


				return IsObjective;
			}
		}
	}
	return nullptr;
}

AObject* BABAGameMode::ObjectiveCheck(int _X, int _Y)
{
	return nullptr;
}