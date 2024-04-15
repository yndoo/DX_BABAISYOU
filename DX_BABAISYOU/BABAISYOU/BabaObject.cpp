#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

ABabaObject::ABabaObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

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

	//SetActorLocation(CalIndexToPos(Index2D{0,0}));
}

void ABabaObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Index2D Test = CalPosToIndex(GetActorLocation());
	int a = 0;

	{
		Index2D Index = CalPosToIndex(GetActorLocation());
		FVector Res = FVector(Index.X, Index.Y);
		std::string Msg = std::format("Index : {}\n", Res.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);

		FVector Pos = CalIndexToPos(Index);
		std::string Msg2 = std::format("IndexToPos : {}\n", Pos.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg2);
	}

	{
		std::string Msg = std::format("Pos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	// �Է��� �־����� -> �ִϸ��̼� ������Ʈ�ؾ���
	if (true == EachInputCheck)
	{
		EachInputCheck = false;	// Super���� ���� ������ ���⼭ false�� �ٲ���.
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}