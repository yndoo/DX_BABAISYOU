#pragma once
#include "Object.h"
#include "ContentsEnum.h"
#include <stack>

// �Է¿� ���� Lerp �̵��ϴ� ���
class ALerpMoveObject : public AObject
{
	GENERATED_BODY(AObject)
public:
	ALerpMoveObject();
	~ALerpMoveObject();

	ALerpMoveObject(const ALerpMoveObject& _Other) = delete;
	ALerpMoveObject(ALerpMoveObject&& _Other) noexcept = delete;
	ALerpMoveObject& operator=(const ALerpMoveObject& _Other) = delete;
	ALerpMoveObject& operator=(ALerpMoveObject&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;

	void Move(float _DeltaTime);
	void ReverseMoveSetting(EInputDir _Dir, float _DeltaTime);
	void AddNextActorLocation(FVector _Add);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);

	EInputDir NewInputDir = EInputDir::Right;
	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;		// 1920*1080 ȯ�濡���� �� Ÿ�� 54*54
	bool IsMove = false;		// �����̴� ������ ��Ÿ���� ����
	//bool IsReverseMove = false;	
	bool InputCheck = false;	// Input�� �־����� �ִϸ��̼��� ����
	int AnimationNumber = 0;
	std::stack<std::pair<int, EInputDir>> MoveStack;	//�ǵ����� ������ �ʿ���
private:
};

