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
		// 문장검사
		//SentenceUpdate();

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
//void BABAGameMode::Update(float _DeltaTime)
//{
//	// 위치 변화가 있는 애들 SetLocation 다시 해주기
//	// Info의 CurIdx는 GMM 바뀔 때 저장해줌.
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