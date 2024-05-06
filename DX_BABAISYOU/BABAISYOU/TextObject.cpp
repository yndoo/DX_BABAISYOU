#include "PreCompile.h"
#include "TextObject.h"
#include "ContentsConstValue.h"

ATextObject::ATextObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::Text);

	Info->MyObjectiveType[EObjectType::PUSH] = true;
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
	if (SentenceON != ON)
	{
		ON = SentenceON;
		AniONOFF();
	}

	if (MyDestroyed != Destroyed)
	{
		if (true == Destroyed)
		{
			Renderer->SetActive(false);
			MyDestroyed = Destroyed;
		}
		else
		{
			Renderer->SetActive(true);
			MyDestroyed = Destroyed;
		}
	}
}

void ATextObject::AniONOFF()
{

}