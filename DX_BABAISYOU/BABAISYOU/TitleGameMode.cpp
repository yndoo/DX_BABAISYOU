#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TextActor.h"

ATitleGameMode::ATitleGameMode()
{
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -200.0f));
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	FVector Pos = FVector(-135, 108);
	FVector TitleScale = FVector(54, 162);
	std::shared_ptr<TextActor> B1 = GetWorld()->SpawnActor<TextActor>("B1");
	B1->SetAnimation("B");
	B1->SetActorLocation(Pos);
	B1->SetRendererScale(TitleScale);
	B1->SetRendererMulColor(FVector(217, 57, 106));

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> A1 = GetWorld()->SpawnActor<TextActor>("A1");
	A1->SetAnimation("A");
	A1->SetActorLocation(Pos);
	A1->SetRendererScale(TitleScale);
	A1->SetRendererMulColor(FVector(217, 57, 106));

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> B2 = GetWorld()->SpawnActor<TextActor>("B2");
	B2->SetAnimation("B");
	B2->SetActorLocation(Pos);
	B2->SetRendererScale(TitleScale);
	B2->SetRendererMulColor(FVector(217, 57, 106));

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> A2 = GetWorld()->SpawnActor<TextActor>("A2");
	A2->SetAnimation("A");
	A2->SetActorLocation(Pos);
	A2->SetRendererScale(TitleScale);
	A2->SetRendererMulColor(FVector(217, 57, 106));


	Pos += FVector(54, 0);
	std::shared_ptr<TextActor> I = GetWorld()->SpawnActor<TextActor>("I");
	I->SetAnimation("I");
	I->SetActorLocation(Pos);
	I->SetRendererScale(TitleScale);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> S = GetWorld()->SpawnActor<TextActor>("S");
	S->SetAnimation("S");
	S->SetActorLocation(Pos);
	S->SetRendererScale(TitleScale);

	Pos += FVector(54, 0);
	std::shared_ptr<TextActor> Y = GetWorld()->SpawnActor<TextActor>("Y");
	Y->SetAnimation("Y");
	Y->SetActorLocation(Pos);
	Y->SetRendererScale(TitleScale);
	Y->SetRendererMulColor(FVector(217, 57, 106));

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> O = GetWorld()->SpawnActor<TextActor>("O");
	O->SetAnimation("O");
	O->SetActorLocation(Pos);
	O->SetRendererScale(TitleScale);
	O->SetRendererMulColor(FVector(217, 57, 106));

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> U = GetWorld()->SpawnActor<TextActor>("U");
	U->SetAnimation("U");
	U->SetActorLocation(Pos);
	U->SetRendererScale(TitleScale);
	U->SetRendererMulColor(FVector(217, 57, 106));
}