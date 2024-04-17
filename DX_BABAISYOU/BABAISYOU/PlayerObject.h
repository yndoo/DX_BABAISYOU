#pragma once
#include <EngineCore/SpriteRenderer.h>
#include "LerpMoveObject.h"


// �÷��̾ �� �� �ִ� ������Ʈ�� (ex : BABA, ROCK, ... �� �̹��� ������Ʈ��)
class APlayerObject : public ALerpMoveObject
{
	GENERATED_BODY(ALerpMoveObject)

public:
	APlayerObject();
	~APlayerObject();

	APlayerObject(const APlayerObject& _Other) = delete;
	APlayerObject(APlayerObject&& _Other) noexcept = delete;
	APlayerObject& operator=(const APlayerObject& _Other) = delete;
	APlayerObject& operator=(APlayerObject&& _Other) noexcept = delete;

	void BeginPosSetting();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CreateObject4DirAnimations(std::string _ObjectName);
	std::string GetAnimationName(std::string _ObjectName, int _AniNum);
private:
};

