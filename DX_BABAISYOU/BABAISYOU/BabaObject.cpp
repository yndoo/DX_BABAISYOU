#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineDebugMsgWindow.h>

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


	{
		Index2D Index = PosToIndex(GetActorLocation());
		FVector Res = FVector(Index.X, Index.Y);
		std::string Msg = std::format("Index : {}\n", Res.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);

		FVector Pos = IndexToPos(Index);
		std::string Msg2 = std::format("IndexToPos : {}\n", Pos.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg2);
	}

	{
		std::string Msg = std::format("Pos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	// �Է��� �־����� -> �ִϸ��̼� ������Ʈ�ؾ���
	if (true == InputCheck)
	{
		InputCheck = false;	// Super���� ���� ������ ���⼭ false�� �ٲ���.
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}