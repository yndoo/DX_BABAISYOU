#pragma once
#include <EngineCore/SpriteRenderer.h>
#include "LerpMoveObject.h"



// 플레이어가 될 수 있는 오브젝트들 (ex : BABA, ROCK, ... 의 이미지 오브젝트들)
// LerpMove 상속받고, 애니메이션 관련 기능들 추가됨
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
	bool DirCheck();
	std::string GetAnimationName(std::string _ObjectName, int _AniNum);

	float AnimationInter = 0.2f;
	
	std::vector<float> AnimationInterVec = { AnimationInter , AnimationInter , AnimationInter };
private:
};

