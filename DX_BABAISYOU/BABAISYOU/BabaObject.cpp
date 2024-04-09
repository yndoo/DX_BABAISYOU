#include "PreCompile.h"
#include "BabaObject.h"

ABabaObject::ABabaObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ABabaObject::~ABabaObject()
{
}


void ABabaObject::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(400.0f, 400.0f, -100.0f));
	CreateObject4DirAnimations("BABA");

	Renderer->ChangeAnimation("BABA_Right0");
}

void ABabaObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	// 입력이 있었으면 -> 애니메이션 업데이트해야함
	if (true == InputCheck)
	{
		InputCheck = false;
		AnimationNumber = (AnimationNumber + 1) % 4;
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}