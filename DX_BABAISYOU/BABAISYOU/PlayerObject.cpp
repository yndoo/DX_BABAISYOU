#include "PreCompile.h"
#include "PlayerObject.h"

APlayerObject::APlayerObject()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::FrontTile);
	Info->TileType = ETileType::Player;
}

APlayerObject::~APlayerObject()
{
}

void APlayerObject::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == EachInputCheck && Info->MyObjectiveType[EObjectType::YOU] == true)
	{
		AnimationNumber = (AnimationNumber + 1) % 4;
	}

	if (false == SentenceON)
	{
		//Info->ObjectiveType = EObjectType::NONE;
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

std::string APlayerObject::GetAnimationName(std::string _ObjectName, int _AniNum)
{
	DirCheck();

	std::string AniDir = "";
	switch (CurDir) {
	case EInputDir::Right:
		AniDir = "_Right";
		break;
	case EInputDir::Left:
		AniDir = "_Left";
		break;
	case EInputDir::Up:
		AniDir = "_Up";
		break;
	case EInputDir::Down:
		AniDir = "_Down";
		break;
	default:
		break;
	}
	return _ObjectName + AniDir + std::to_string(_AniNum);
}

void APlayerObject::CreateObject4DirAnimations(std::string _ObjectName)
{
	int j = 1;
	for (int i = j; i < j + 4; i++)	//BABA_Right0 ~ BABA_Right3
	{
		Renderer->CreateAnimation(_ObjectName + "_Right" + std::to_string(i - j), _ObjectName + ".png", AnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
	j += 4;
	for (int i = j; i < j + 4; i++)	//BABA_Up0 ~ BABA_Up3 
	{
		Renderer->CreateAnimation(_ObjectName + "_Up" + std::to_string(i - j), _ObjectName + ".png", AnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
	j += 4;
	for (int i = j; i < j + 4; i++)	//BABA_Left0 ~ BABA_Left3
	{
		Renderer->CreateAnimation(_ObjectName + "_Left" + std::to_string(i - j), _ObjectName + ".png", AnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
	j += 4;
	for (int i = j; i < j + 4; i++)	//BABA_Down0 ~ BABA_Down3
	{
		Renderer->CreateAnimation(_ObjectName + "_Down" + std::to_string(i - j), _ObjectName + ".png", AnimationInterVec, { i, i + 17, i + 17 * 2 }, true);
	}
}