#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TextActor.h"
#include <EngineCore/EngineCore.h>

ATitleGameMode::ATitleGameMode()
{
	InputOn();
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

	if (true == IsDown(VK_UP))
	{
		UEngineSound::SoundPlay("OptionCursorSound.ogg");
		Cursor->SetPosition(FVector(-330, -100));
	}
	if (true == IsDown(VK_DOWN))
	{
		UEngineSound::SoundPlay("OptionCursorSound.ogg");
		Cursor->SetPosition(FVector(-330, -200));
	}
	if (true == IsDown(VK_SPACE))
	{
		UEngineSound::SoundPlay("OptionSelect.ogg");
		FVector Pos = Cursor->GetLocalPosition();
		if (Pos.Y == -100)
		{
			GEngine->ChangeLevel("SelectMapLevel");
		}
		else if (Pos.Y == -200)
		{
			// 게임종료
			GEngine->EngineWindow.Off();
		}
	}
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	BGMPlayer = UEngineSound::SoundPlay("TitleBGM.mp3");
	BGMPlayer.SetVolume(0.3f);
	BGMPlayer.Loop(100);

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

	StartBtn = CreateWidget<UImage>(GetWorld(), "StartBtn");
	StartBtn->AddToViewPort(1);
	StartBtn->SetSprite("StartTheGameBtn.png");
	StartBtn->SetScale({ 589,76 });
	StartBtn->SetPosition(FVector(0, -100));


	ExitBtn = CreateWidget<UImage>(GetWorld(), "ExitBtn");
	ExitBtn->AddToViewPort(1);
	ExitBtn->SetSprite("ExitTheGameBtn.png");
	ExitBtn->SetScale({ 589,76 });
	ExitBtn->SetPosition(FVector(0, -200));

	Cursor = CreateWidget<UImage>(GetWorld(), "Cursor");
	Cursor->AddToViewPort(1);
	Cursor->CreateAnimation("BabaCursor", "BABA.png", { 0.2f, 0.2f, 0.2f }, { 1, 18, 35 }, true);
	Cursor->ChangeAnimation("BabaCursor");
	Cursor->SetScale({ 54, 54 });
	Cursor->SetPosition(FVector(-330, -100));
}