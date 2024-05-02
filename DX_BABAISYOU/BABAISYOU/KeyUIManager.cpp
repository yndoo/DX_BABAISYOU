#include "PreCompile.h"
#include "KeyUIManager.h"
#include "TextActor.h"

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
}

void KeyUIManager::CreateUI()
{
	UImage* UndoKey = CreateWidget<UImage>(GetWorld(), "UndoKey");
	UndoKey->AddToViewPort(1);
	UndoKey->SetSprite("UndoKey.png");
	UndoKey->SetScale({ 36,36 });
	UndoKey->SetPosition(FVector(-270, 324));

	UImage* RestartKey = CreateWidget<UImage>(GetWorld(), "RestartKey");
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

		std::shared_ptr<TextActor> N = GetWorld()->SpawnActor<TextActor>("N");
		Pos = Pos + FVector(18, 0);
		N->SetAnimation("N");
		N->SetActorLocation(Pos);

		std::shared_ptr<TextActor> D = GetWorld()->SpawnActor<TextActor>("D");
		Pos = Pos + FVector(18, 0);
		D->SetAnimation("D");
		D->SetActorLocation(Pos);

		std::shared_ptr<TextActor> O = GetWorld()->SpawnActor<TextActor>("O");
		Pos = Pos + FVector(18, 0);
		O->SetAnimation("O");
		O->SetActorLocation(Pos);
	}

	{
		/*RESTART ±Û¾¾*/
		FVector Pos = FVector(198 + 30, 324);
		std::shared_ptr<TextActor> R = GetWorld()->SpawnActor<TextActor>("R");
		Pos = Pos + FVector(18, 0);
		R->SetAnimation("R");
		R->SetActorLocation(Pos);

		std::shared_ptr<TextActor> E = GetWorld()->SpawnActor<TextActor>("E");
		Pos = Pos + FVector(18, 0);
		E->SetAnimation("E");
		E->SetActorLocation(Pos);

		std::shared_ptr<TextActor> S = GetWorld()->SpawnActor<TextActor>("S");
		Pos = Pos + FVector(18, 0);
		S->SetAnimation("S");
		S->SetActorLocation(Pos);

		std::shared_ptr<TextActor> T = GetWorld()->SpawnActor<TextActor>("T");
		Pos = Pos + FVector(18, 0);
		T->SetAnimation("T");
		T->SetActorLocation(Pos);

		std::shared_ptr<TextActor> A = GetWorld()->SpawnActor<TextActor>("A");
		Pos = Pos + FVector(18, 0);
		A->SetAnimation("A");
		A->SetActorLocation(Pos);

		std::shared_ptr<TextActor> R2 = GetWorld()->SpawnActor<TextActor>("R");
		Pos = Pos + FVector(18, 0);
		R2->SetAnimation("R");
		R2->SetActorLocation(Pos);

		std::shared_ptr<TextActor> T2 = GetWorld()->SpawnActor<TextActor>("T");
		Pos = Pos + FVector(18, 0);
		T2->SetAnimation("T");
		T2->SetActorLocation(Pos);
	}
}