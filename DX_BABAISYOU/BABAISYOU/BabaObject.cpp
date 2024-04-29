#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

ABabaObject::ABabaObject()
{
	InputOn();	// �ϴ� �ѵ�
	Info->MyType = EObjectType::BABA;
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
	if (true == EachInputCheck || true == ZInputCheck)
	{
		EachInputCheck = false;	// Super���� ���� ������ ���⼭ false�� �ٲ���.
		ZInputCheck = false;
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}