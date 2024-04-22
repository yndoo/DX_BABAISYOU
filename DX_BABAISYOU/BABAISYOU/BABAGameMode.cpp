#include "PreCompile.h"
#include "BABAGameMode.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/EngineCore.h>
#include "ContentsConstValue.h"

#include "BabaObject.h"
#include "WallObject.h"
#include "FlagObject.h"
#include "WaterObject.h"
#include "RockObject.h"

#include "IsText.h"
#include "BabaText.h"
#include "YouText.h"
#include "WallText.h"
#include "FlagText.h"
#include "WaterText.h"
#include "StopText.h"
#include "WinText.h"
#include "PushText.h"
#include "DefeatText.h"
#include "SinkText.h"
#include "RockText.h"

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
		DeathCheck();
		UContentsConstValue::ZInput = false;
		BeforeInputCount = UContentsConstValue::InputCount;
		return;
	}
	else
	{
		if (BeforeInputCount != UContentsConstValue::InputCount)
		{
			StackUpdate();
			BeforeInputCount = UContentsConstValue::InputCount;
		}
		SentenceUpdate();
		FinalUpdate();
		DeathCheck();
	}
}

void BABAGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void BABAGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Update();
	
	//if (BeforeInputCount != UContentsConstValue::InputCount)
	//{
	//	Update();
	//	BeforeInputCount = UContentsConstValue::InputCount;
	//}
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

// TEXT�� PLAYER ��ü �̾��ִ� �Լ�
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
				player->Info->MyObjectiveType[sub->Info->TextObjective] = true;
				int a = 0;
			}
		}
	}
}

// �װų� �̱�� ��Ȳ�� üũ���ִ� �Լ�
void BABAGameMode::DeathCheck()
{
	int YouCount = 0;
	for (AObject* Obj : Players)
	{
		if (Obj->Info->MyObjectiveType[EObjectType::YOU] == true)
		{
			++YouCount;
			Index2D YouPos = Obj->Info->CurIndex;
			
			//std::list<AObject*> test = GMapManager->Graph[YouPos.X][YouPos.Y];

			bool Changed = false;
			for (AObject* others : GMapManager->Graph[YouPos.X][YouPos.Y])
			{
				if (others->Info->MyObjectiveType[EObjectType::DEFEAT] == true)
				{
					//Obj�� �ı�
					--YouCount;
					Obj->Destroyed = true;
					Changed = true;
					continue;
				}
				if (
					others->Info->MyObjectiveType[EObjectType::SINK] == true
					//&& Obj->Info->MyObjectiveType[EObjectType::FLOAT] == false
					)
				{
					//Obj�� others�� �Ѵ� �ı�
					--YouCount;
					Obj->Destroyed = true;
					others->Destroyed = true;
					Changed = true;
					continue;
					//return;
				}
				if (others->Info->MyObjectiveType[EObjectType::WIN] == true)
				{
					// ���� �¸�
					//GEngine->ChangeLevel("SelectMapLevel");
					//return;
				}
			}
			if (false == Changed)
			{
				Obj->Destroyed = false;
			}
		}
	}
	YouCount;
	if (0 == YouCount)
	{
		// ���� ����
		//GEngine->ChangeLevel("SelectMapLevel");
		int a = 0;
		return;
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
			obj->Info->MyObjectiveType.clear();
			//for (auto types : obj->Info->MyObjectiveType)
			//{
			//	types.second = false;
			//}
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
			if (sub->Info->MyType == EObjectType::WATERTEXT)
			{
				int a = 0;
			}

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

void BABAGameMode::AutoCreate(EObjectType _ObjectType, int _X, int _Y, FVector _MapScale, int _TileNum/* = 0*/)
{
	switch (_ObjectType)
	{
	case EObjectType::NONE:
		break;
	// PlayerObjects
	case EObjectType::BABA:
	{
		std::shared_ptr<ABabaObject> Baba = GetWorld()->SpawnActor<ABabaObject>("Baba");
		Baba->SetMapScale(_MapScale);
		Baba->SetMaxIndex();
		Baba->AddActorLocation(Baba->CalIndexToPos(Index2D(_X, _Y)));
		Baba->BeginPosSetting();
		Baba->SetOrder(ERenderOrder::FrontTile);
		AllObjects.push_back(Baba.get());
		Players.push_back(Baba.get());
		GMapManager->SetObject(Baba.get(), _X, _Y);
	}
		break;
	case EObjectType::WALL:
	{
		std::shared_ptr<AWallObject> Wall = GetWorld()->SpawnActor<AWallObject>("Wall");
		Wall->SetTileNum(_TileNum);
		Wall->SetMapScale(_MapScale);
		Wall->SetMaxIndex();
		Wall->SetActorLocation(Wall->CalIndexToPos(Index2D(_X, _Y)));
		Wall->BeginPosSetting();
		Wall->SetOrder(ERenderOrder::BackTile);
		GMapManager->SetObject(Wall.get(), _X, _Y);
		AllObjects.push_back(Wall.get());
		Players.push_back(Wall.get());
	}
		break;
	case EObjectType::WATER:
	{
		std::shared_ptr<AWaterObject> Water = GetWorld()->SpawnActor<AWaterObject>("Water");
		Water->SetTileNum(_TileNum);
		Water->SetMapScale(_MapScale);
		Water->SetMaxIndex();
		Water->SetActorLocation(Water->CalIndexToPos(Index2D(_X, _Y)));
		Water->BeginPosSetting();
		Water->SetOrder(ERenderOrder::BackTile);
		GMapManager->SetObject(Water.get(), _X, _Y);
		AllObjects.push_back(Water.get());
		Players.push_back(Water.get());
	}
	break;
	case EObjectType::FLAG:
	{
		std::shared_ptr<AFlagObject> Flag = GetWorld()->SpawnActor<AFlagObject>("Flag");
		Flag->SetMapScale(_MapScale);
		Flag->SetMaxIndex();
		Flag->SetActorLocation(Flag->CalIndexToPos(Index2D(_X, _Y)));
		Flag->BeginPosSetting();
		Flag->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Flag.get(), _X, _Y);
		AllObjects.push_back(Flag.get());
		Players.push_back(Flag.get());
	}
		break;
	case EObjectType::ROCK:
	{
		std::shared_ptr<ARockObject> Rock = GetWorld()->SpawnActor<ARockObject>("Rock");
		Rock->SetMapScale(_MapScale);
		Rock->SetMaxIndex();
		Rock->SetActorLocation(Rock->CalIndexToPos(Index2D(_X, _Y)));
		Rock->BeginPosSetting();
		Rock->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Rock.get(), _X, _Y);
		AllObjects.push_back(Rock.get());
		Players.push_back(Rock.get());
	}
	break;
	// ObjectiveObjects
	case EObjectType::YOU:
	{
		std::shared_ptr<AYouText> YOU = GetWorld()->SpawnActor<AYouText>("YOUText");
		YOU->SetMapScale(_MapScale);
		YOU->SetMaxIndex();
		YOU->AddActorLocation(YOU->CalIndexToPos(Index2D(_X, _Y)));
		YOU->BeginPosSetting();
		YOU->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(YOU.get(), _X, _Y);
		AllObjects.push_back(YOU.get());
		Texts.push_back(YOU.get());
	}
		break;
	case EObjectType::PUSH:
	{
		std::shared_ptr<APushText> Push = GetWorld()->SpawnActor<APushText>("PUSHText");
		Push->SetMapScale(_MapScale);
		Push->SetMaxIndex();
		Push->AddActorLocation(Push->CalIndexToPos(Index2D(_X, _Y)));
		Push->BeginPosSetting();
		Push->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Push.get(), _X, _Y);
		AllObjects.push_back(Push.get());
		Texts.push_back(Push.get());
	}
		break;
	case EObjectType::STOP:
	{
		std::shared_ptr<AStopText> Stop = GetWorld()->SpawnActor<AStopText>("StopText");
		Stop->SetMapScale(_MapScale);
		Stop->SetMaxIndex();
		Stop->AddActorLocation(Stop->CalIndexToPos(Index2D(_X, _Y)));
		Stop->BeginPosSetting();
		Stop->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Stop.get(), _X, _Y);
		AllObjects.push_back(Stop.get());
		Texts.push_back(Stop.get());
	}
		break;
	case EObjectType::WIN:
	{
		std::shared_ptr<AWinText> Win = GetWorld()->SpawnActor<AWinText>("WinText");
		Win->SetMapScale(_MapScale);
		Win->SetMaxIndex();
		Win->AddActorLocation(Win->CalIndexToPos(Index2D(_X, _Y)));
		Win->BeginPosSetting();
		Win->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Win.get(), _X, _Y);
		AllObjects.push_back(Win.get());
		Texts.push_back(Win.get());
	}
		break;
	case EObjectType::DEFEAT:
	{
		std::shared_ptr<ADefeatText> Defeat = GetWorld()->SpawnActor<ADefeatText>("DefeatText");
		Defeat->SetMapScale(_MapScale);
		Defeat->SetMaxIndex();
		Defeat->AddActorLocation(Defeat->CalIndexToPos(Index2D(_X, _Y)));
		Defeat->BeginPosSetting();
		Defeat->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Defeat.get(), _X, _Y);
		AllObjects.push_back(Defeat.get());
		Texts.push_back(Defeat.get());
	}
		break;
	case EObjectType::SINK:
	{
		std::shared_ptr<ASinkText> Sink = GetWorld()->SpawnActor<ASinkText>("SinkText");
		Sink->SetMapScale(_MapScale);
		Sink->SetMaxIndex();
		Sink->AddActorLocation(Sink->CalIndexToPos(Index2D(_X, _Y)));
		Sink->BeginPosSetting();
		Sink->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(Sink.get(), _X, _Y);
		AllObjects.push_back(Sink.get());
		Texts.push_back(Sink.get());
	}
		break;
	// VerbObejcts
	case EObjectType::IS:
	{
		std::shared_ptr<AIsText> IS = GetWorld()->SpawnActor<AIsText>("IS");
		IS->SetMapScale(_MapScale);
		IS->SetMaxIndex();
		IS->AddActorLocation(IS->CalIndexToPos(Index2D(_X, _Y)));
		IS->BeginPosSetting();
		IS->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(IS.get(), _X, _Y);
		AllObjects.push_back(IS.get());
		Texts.push_back(IS.get());
	}
		break;
	// SubjectObjects
	case EObjectType::BABATEXT:
	{
		std::shared_ptr<ABabaText> BaText = GetWorld()->SpawnActor<ABabaText>("BabaText");
		BaText->SetMapScale(_MapScale);
		BaText->SetMaxIndex();
		BaText->AddActorLocation(BaText->CalIndexToPos(Index2D(_X, _Y)));
		BaText->BeginPosSetting();
		BaText->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(BaText.get(), _X, _Y);
		AllObjects.push_back(BaText.get());
		Texts.push_back(BaText.get());
	}
		break;
	case EObjectType::WALLTEXT:
	{
		std::shared_ptr<AWallText> WallText = GetWorld()->SpawnActor<AWallText>("WallText");
		WallText->SetMapScale(_MapScale);
		WallText->SetMaxIndex();
		WallText->AddActorLocation(WallText->CalIndexToPos(Index2D(_X, _Y)));
		WallText->BeginPosSetting();
		WallText->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(WallText.get(), _X, _Y);
		AllObjects.push_back(WallText.get());
		Texts.push_back(WallText.get());
	}
		break;
	case EObjectType::FLAGTEXT:
	{
		std::shared_ptr<AFlagText> FlagText = GetWorld()->SpawnActor<AFlagText>("FlagText");
		FlagText->SetMapScale(_MapScale);
		FlagText->SetMaxIndex();
		FlagText->SetActorLocation(FlagText->CalIndexToPos(Index2D(_X, _Y)));
		FlagText->BeginPosSetting();
		FlagText->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(FlagText.get(), _X, _Y);
		AllObjects.push_back(FlagText.get());
		Texts.push_back(FlagText.get());
	}
		break;
	case EObjectType::WATERTEXT:
	{
		std::shared_ptr<AWaterText> WaterText = GetWorld()->SpawnActor<AWaterText>("WaterText");
		WaterText->SetMapScale(_MapScale);
		WaterText->SetMaxIndex();
		WaterText->SetActorLocation(WaterText->CalIndexToPos(Index2D(_X, _Y)));
		WaterText->BeginPosSetting();
		WaterText->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(WaterText.get(), _X, _Y);
		AllObjects.push_back(WaterText.get());
		Texts.push_back(WaterText.get());
	}
	break;
	case EObjectType::ROCKTEXT:
	{
		std::shared_ptr<ARockText> RockText = GetWorld()->SpawnActor<ARockText>("ARockText");
		RockText->SetMapScale(_MapScale);
		RockText->SetMaxIndex();
		RockText->SetActorLocation(RockText->CalIndexToPos(Index2D(_X, _Y)));
		RockText->BeginPosSetting();
		RockText->SetOrder(ERenderOrder::FrontTile);
		GMapManager->SetObject(RockText.get(), _X, _Y);
		AllObjects.push_back(RockText.get());
		Texts.push_back(RockText.get());
	}
	break;
	default:
		break;
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