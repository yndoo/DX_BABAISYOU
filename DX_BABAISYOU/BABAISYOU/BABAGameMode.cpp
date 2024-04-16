#include "PreCompile.h"
#include "BABAGameMode.h"
#include <EngineCore/EngineDebugMsgWindow.h>

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
}

//void BABAGameMode::Update(float _DeltaTime)
//{
//	// ��ġ ��ȭ�� �ִ� �ֵ� SetLocation �ٽ� ���ֱ�
//	// Info�� CurIdx�� GMM �ٲ� �� ��������.
//	for (auto Obj : AllObjects)
//	{
//		Index2D Cur = Obj->Info->CurIdx;
//		Index2D Before = Obj->CalPosToIndex(Obj->GetActorLocation());
//		if (Cur != Before)
//		{
//			//GMapManager->Graph[Before.X][Before.Y].remove(Obj);
//			//GMapManager->Graph[Cur.X][Cur.Y].push_back(Obj);
//			//Obj->
//		}
//	}
//}

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