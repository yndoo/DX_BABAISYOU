#include "PreCompile.h"
#include "BabaObject.h"
#include <EngineCore/EngineTexture.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>

ABabaObject::ABabaObject()
{
	InputOn();	// 일단 켜둠
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

	Index2D Test = CalPosToIndex(GetActorLocation());
	int a = 0;

	//{
		Index2D Index = CalPosToIndex(GetActorLocation());
		FVector Res = FVector(Index.X, Index.Y);
		FVector Res2 = FVector(this->Info->CurIndex.X, this->Info->CurIndex.Y);
		std::string Msg = std::format("Loc_Index : {}, Info_Index : {} \n", Res.ToString(), Res2.ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);

	//	FVector Pos = CalIndexToPos(Index);
	//	std::string Msg2 = std::format("IndexToPos : {}\n", Pos.ToString());
	//	UEngineDebugMsgWindow::PushMsg(Msg2);
	//}

	//{
	//	std::string Msg = std::format("Pos : {}\n", GetActorLocation().ToString());
	//	UEngineDebugMsgWindow::PushMsg(Msg);
	//}

	// 입력이 있었으면 -> 애니메이션 업데이트해야함
	if (true == EachInputCheck || true == ZInputCheck)
	{
		EachInputCheck = false;	// Super먼저 돌기 때문에 여기서 false로 바꿔줌.
		ZInputCheck = false;
		Renderer->ChangeAnimation(GetAnimationName("BABA", AnimationNumber));
	}
}