#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineDebugMsgWindow.h>

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

	// 입력이 있었으면 -> 애니메이션 업데이트해야함
	if (true == InputCheck)
	{
		InputCheck = false;	// Super먼저 돌기 때문에 여기서 false로 바꿔줌.
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}