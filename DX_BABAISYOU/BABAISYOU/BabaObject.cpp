#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>

ABabaObject::ABabaObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();	// �ϴ� �ѵ�
}

ABabaObject::~ABabaObject()
{
}


void ABabaObject::BeginPlay()
{
	Super::BeginPlay();
	CreateObject4DirAnimations("BABA");
	Renderer->ChangeAnimation("BABA_Right0");
}

void ABabaObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	// �Է��� �־����� -> �ִϸ��̼� ������Ʈ�ؾ���
	if (true == InputCheck)
	{
		InputCheck = false;	// Super���� ���� ������ ���⼭ false�� �ٲ���.
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}