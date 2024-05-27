#include "PreCompile.h"
#include "ChangingGameMode.h"
#include "ContentsConstValue.h"

AChangingGameMode::AChangingGameMode()
{
	InputOn();
}

AChangingGameMode::~AChangingGameMode()
{
}

void AChangingGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -200.0f));

	FVector Pos = FVector(-108, 72);
	std::shared_ptr<TextActor> L = GetWorld()->SpawnActor<TextActor>("L");
	L->SetAnimation("L");
	L->SetActorLocation(Pos);
	L->SetRendererScale(TextScale);
	L->SetRendererMulColor(Col);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> E = GetWorld()->SpawnActor<TextActor>("E");
	E->SetAnimation("E");
	E->SetActorLocation(Pos);
	E->SetRendererScale(TextScale);
	E->SetRendererMulColor(Col);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> V = GetWorld()->SpawnActor<TextActor>("V");
	V->SetAnimation("V");
	V->SetActorLocation(Pos);
	V->SetRendererScale(TextScale);
	V->SetRendererMulColor(Col);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> E2 = GetWorld()->SpawnActor<TextActor>("E2");
	E2->SetAnimation("E");
	E2->SetActorLocation(Pos);
	E2->SetRendererScale(TextScale);
	E2->SetRendererMulColor(Col);

	Pos += FVector(27, 0);
	std::shared_ptr<TextActor> L2 = GetWorld()->SpawnActor<TextActor>("L");
	L2->SetAnimation("L");
	L2->SetActorLocation(Pos);
	L2->SetRendererScale(TextScale);
	L2->SetRendererMulColor(Col);

	Pos += FVector(54, 0);
	std::shared_ptr<AStageNumber> StageNum1 = GetWorld()->SpawnActor<AStageNumber>("StageNum1");
	StageNum1->SetMapScale(UContentsConstValue::StageSelectMapScale);
	StageNum1->AddActorLocation(FVector(81, 63));
	StageNum1->BeginPosSetting();
	StageNum1->SetStageNum(0);
	StageNum1->SetActorScale3D(FVector(72, 72));
	StageNum1->SetRendererMulColor(Col);
}

void AChangingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	PassTime -= _DeltaTime;

	if (PassTime < 0.f || true == IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("StageLevel");
	}
}

void AChangingGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	MakeTitle(UContentsConstValue::OpenStageNum);

	PassTime = 3.f;

	StageNum2 = GetWorld()->SpawnActor<AStageNumber>("StageNum2");
	StageNum2->SetMapScale(UContentsConstValue::StageSelectMapScale);

	StageNum2->AddActorLocation(FVector(108, 63));
	StageNum2->BeginPosSetting();
	StageNum2->SetStageNum(UContentsConstValue::OpenStageNum);
	StageNum2->SetActorScale3D(FVector(72, 72));
	StageNum2->SetRendererMulColor(Col);
}

void AChangingGameMode::LevelEnd(ULevel* _NextLevel)
{
	StageNum2->Destroy();

	Title->SetActive(false);
}

void AChangingGameMode::MakeTitle(int StageNum)
{
	if (Title != nullptr)
	{
		Title->SetActive(false);
	}
	Title = CreateWidget<UImage>(GetWorld(), "Title");
	Title->AddToViewPort(1);
	std::string str = "Title0" + std::to_string(StageNum) + ".png";
	Title->SetSprite(str);
	Title->SetAutoSize(0.85f, true);
	Title->SetPosition(FVector(0, 0));
}