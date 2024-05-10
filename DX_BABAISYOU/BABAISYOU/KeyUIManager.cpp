#include "PreCompile.h"
#include "KeyUIManager.h"

KeyUIManager::KeyUIManager()
{
}

KeyUIManager::~KeyUIManager()
{
}

void KeyUIManager::BeginPlay()
{
	Super::BeginPlay();
	CreateUI();
}

void KeyUIManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CurOn;
	int a = 0;
}

void KeyUIManager::KeyUIOn()
{
	if(false == CurOn)
	{
		SP = UEngineSound::SoundPlay("GameOver.ogg");
		UndoKey->SetActive(true);
		RestartKey->SetActive(true);
		for (int i = 0; i < TextActors.size(); i++)
		{
			TextActors[i]->SetActive(true);
		}
	}
	CurOn = true;
}

void KeyUIManager::KeyUIOff()
{
	if(true == CurOn)
	{
		SP.Off();
		UndoKey->SetActive(false);
		RestartKey->SetActive(false);
		for (int i = 0; i < TextActors.size(); i++)
		{
			TextActors[i]->SetActive(false);
		}
	}
	CurOn = false;
	int a = 0;
}

void KeyUIManager::CreateUI()
{
	UndoKey = CreateWidget<UImage>(GetWorld(), "UndoKey");
	UndoKey->AddToViewPort(1);
	UndoKey->SetSprite("UndoKey.png");
	UndoKey->SetScale({ 36,36 });
	UndoKey->SetPosition(FVector(-270, 324));
	

	RestartKey = CreateWidget<UImage>(GetWorld(), "RestartKey");
	RestartKey->AddToViewPort(1);
	RestartKey->SetSprite("RestartKey.png");
	RestartKey->SetScale({ 36,36 });
	RestartKey->SetPosition(FVector(198, 324));

	{
		/*UNDO ±Û¾¾*/
		FVector Pos = FVector(-270 + 30, 324);
		std::shared_ptr<TextActor> U = GetWorld()->SpawnActor<TextActor>("U");
		Pos = Pos + FVector(18, 0);
		U->SetAnimation("U");
		U->SetActorLocation(Pos);
		TextActors.push_back(U.get());


		std::shared_ptr<TextActor> N = GetWorld()->SpawnActor<TextActor>("N");
		Pos = Pos + FVector(18, 0);
		N->SetAnimation("N");
		N->SetActorLocation(Pos);
		TextActors.push_back(N.get());

		std::shared_ptr<TextActor> D = GetWorld()->SpawnActor<TextActor>("D");
		Pos = Pos + FVector(18, 0);
		D->SetAnimation("D");
		D->SetActorLocation(Pos);
		TextActors.push_back(D.get());

		std::shared_ptr<TextActor> O = GetWorld()->SpawnActor<TextActor>("O");
		Pos = Pos + FVector(18, 0);
		O->SetAnimation("O");
		O->SetActorLocation(Pos);
		TextActors.push_back(O.get());
	}

	{
		/*RESTART ±Û¾¾*/
		FVector Pos = FVector(198 + 30, 324);
		std::shared_ptr<TextActor> R = GetWorld()->SpawnActor<TextActor>("R");
		Pos = Pos + FVector(18, 0);
		R->SetAnimation("R");
		R->SetActorLocation(Pos);
		TextActors.push_back(R.get());

		std::shared_ptr<TextActor> E = GetWorld()->SpawnActor<TextActor>("E");
		Pos = Pos + FVector(18, 0);
		E->SetAnimation("E");
		E->SetActorLocation(Pos);
		TextActors.push_back(E.get());

		std::shared_ptr<TextActor> S = GetWorld()->SpawnActor<TextActor>("S");
		Pos = Pos + FVector(18, 0);
		S->SetAnimation("S");
		S->SetActorLocation(Pos);
		TextActors.push_back(S.get());

		std::shared_ptr<TextActor> T = GetWorld()->SpawnActor<TextActor>("T");
		Pos = Pos + FVector(18, 0);
		T->SetAnimation("T");
		T->SetActorLocation(Pos);
		TextActors.push_back(T.get());

		std::shared_ptr<TextActor> A = GetWorld()->SpawnActor<TextActor>("A");
		Pos = Pos + FVector(18, 0);
		A->SetAnimation("A");
		A->SetActorLocation(Pos);
		TextActors.push_back(A.get());

		std::shared_ptr<TextActor> R2 = GetWorld()->SpawnActor<TextActor>("R");
		Pos = Pos + FVector(18, 0);
		R2->SetAnimation("R");
		R2->SetActorLocation(Pos);
		TextActors.push_back(R2.get());

		std::shared_ptr<TextActor> T2 = GetWorld()->SpawnActor<TextActor>("T");
		Pos = Pos + FVector(18, 0);
		T2->SetAnimation("T");
		T2->SetActorLocation(Pos);
		TextActors.push_back(T2.get());
	}
}