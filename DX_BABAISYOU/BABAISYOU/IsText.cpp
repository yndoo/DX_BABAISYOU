#include "PreCompile.h"
#include "IsText.h"

AIsText::AIsText()
{
	Info->TileType = ETileType::Verb;
	Info->MyType = EObjectType::IS;
}

AIsText::~AIsText()
{
}

void AIsText::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("IS_ON", "IS.png", AnimationInterVec, { 0, 2, 4 }, true);
	Renderer->CreateAnimation("IS_OFF", "IS.png", AnimationInterVec, { 1, 3, 5 }, true);

	// 스테이지에 이미 완성되어 있는 문장에서 소리나지 않기 위함
	Renderer->ChangeAnimation("IS_ON");
	Info->MyColor = FVector(255, 255, 255);
	ON = true;	
}

void AIsText::Tick(float _DeltaTime)
{
	//Super::Tick(_DeltaTime);
	ALerpMoveObject::Tick(_DeltaTime);

	if (ON != SentenceON)
	{
		ON = SentenceON;
		AniONOFF();
	}
}

void AIsText::AniONOFF()
{
	if (ON)
	{
		UEngineSound::SoundPlay("SentenceMatchSound.ogg");
		Renderer->ChangeAnimation("IS_ON");
		Info->MyColor = FVector(255, 255, 255);
	}
	else
	{
		Renderer->ChangeAnimation("IS_OFF");
		Info->MyColor = FVector(115, 115, 115);
	}
}