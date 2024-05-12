#include "PreCompile.h"
#include "EndingGameMode.h"

AEndingGameMode::AEndingGameMode()
{
	InputOn();
}

AEndingGameMode::~AEndingGameMode()
{
}

void AEndingGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -200.0f));


	FVector Pos = FVector(-108, 0);
	FVector TitleScale = FVector(54, 54);
	std::shared_ptr<TextActor> T = GetWorld()->SpawnActor<TextActor>("T");
	T->SetAnimation("T");
	T->SetActorLocation(Pos);
	T->SetRendererScale(TitleScale);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> H = GetWorld()->SpawnActor<TextActor>("H");
	H->SetAnimation("H");
	H->SetActorLocation(Pos);
	H->SetRendererScale(TitleScale);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> E = GetWorld()->SpawnActor<TextActor>("E");
	E->SetAnimation("E");
	E->SetActorLocation(Pos);
	E->SetRendererScale(TitleScale);

	Pos += FVector(54, 0);
	std::shared_ptr<TextActor> E2 = GetWorld()->SpawnActor<TextActor>("E2");
	E2->SetAnimation("E");
	E2->SetActorLocation(Pos);
	E2->SetRendererScale(TitleScale);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> N = GetWorld()->SpawnActor<TextActor>("N");
	N->SetAnimation("N");
	N->SetActorLocation(Pos);
	N->SetRendererScale(TitleScale);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> D = GetWorld()->SpawnActor<TextActor>("D");
	D->SetAnimation("D");
	D->SetActorLocation(Pos);
	D->SetRendererScale(TitleScale);
}

void AEndingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsDown(VK_SPACE))
	{
		GEngine->EngineWindow.Off();
	}
}

void AEndingGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	BGMPlayer = UEngineSound::SoundPlay("GameOver.ogg");
	BGMPlayer.SetVolume(0.4f);
	BGMPlayer.Loop(100);

}