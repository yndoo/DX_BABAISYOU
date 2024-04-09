#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>

ABabaObject::ABabaObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();	// 일단 켜둠
}

ABabaObject::~ABabaObject()
{
}


void ABabaObject::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(36.f, 36.f, -100.0f));	// 이미지 한 칸 크기 그대로
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