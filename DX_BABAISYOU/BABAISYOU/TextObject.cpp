#include "PreCompile.h"
#include "TextObject.h"
#include "ContentsConstValue.h"

ATextObject::ATextObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Info->ObjectiveType = EObjectType::PUSH;
}

ATextObject::~ATextObject()
{
}

void ATextObject::BeginPlay()
{
	Super::BeginPlay();
	BeginPosSetting();
}

void ATextObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}