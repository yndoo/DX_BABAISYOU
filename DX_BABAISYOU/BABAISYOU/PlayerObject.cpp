#include "PreCompile.h"
#include "PlayerObject.h"

APlayerObject::APlayerObject()
{

}

APlayerObject::~APlayerObject()
{
}

void APlayerObject::BeginPlay()
{
	Super::BeginPlay();
	BeginPosSetting();
}

void APlayerObject::BeginPosSetting()
{
	// ������ �ֵ� Location �������ְ��� �ٽ� �������.
	CurActorLocation = GetActorLocation();
}

void APlayerObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	DirCheck();
	Move(_DeltaTime);
	if (true == IsMove)
	{
		LerpMove(_DeltaTime);
	}
	

	if (true == IsPress('Z') && false == IsMove)
	{
		if (true == MoveStack.empty())
		{
			return;
		}
		IsMove = true;
		InputCheck = true;

		// �̵� : ���� ������ �ݴ�� �̵�
		ReverseMoveSetting(NewInputDir, _DeltaTime);
		
		// �ִϸ��̼ǿ� �ʿ��� ���� : ���� ������ ������ �ǵ����� ����
		NewInputDir = MoveStack.top().second;
		AnimationNumber = MoveStack.top().first;
		MoveStack.pop();
		return;
	}

	if (true == InputCheck)
	{
		// ���ο� �Է��� �̵��� �ݿ��ϱ� �� ������ ����
		MoveStack.push(std::make_pair(AnimationNumber, CurDir)); 

		AnimationNumber = (AnimationNumber + 1) % 4;
	}
}

bool APlayerObject::DirCheck()
{
	if (CurDir != NewInputDir)
	{
		CurDir = NewInputDir;
		return true;
	}
	return false;
}

std::string APlayerObject::GetAnimationName(std::string _ObjectName, int _AniNum)
{
	DirCheck();

	std::string AniDir = "";
	switch (NewInputDir) {
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