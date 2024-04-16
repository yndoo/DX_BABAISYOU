#pragma once
#include "Object.h"
#include "ContentsEnum.h"

// �Է¿� ���� Lerp �̵��ϴ� ���, (���� : �з��� Lerp �̵��ϴ� ��ɵ� �� �� �־�� ��)
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

	void SetIsMove(bool _IsMove) 
	{
		IsMove = _IsMove;
	}

	void SetCurDir(EInputDir _Dir)
	{
		CurDir = _Dir;
	}

	void AddNextActorLocation(FVector _Add);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void Update(float _DeltaTime);

	void InputMove(float _DeltaTime);
	void ReverseMoveSetting(EInputDir _Dir, float _DeltaTime, bool _CanMove);
	void LerpMove(float _DeltaTime);
	FVector LerpCal(float _Time);

	FVector CurActorLocation = FVector::Zero;
	FVector NextActorLocation = FVector::Zero;
	float LerpTime = 0.f;
	float TileSize = 36.f;					// 1920*1080 ȯ�濡���� �� Ÿ�� 54*54
	bool IsMove = false;					// �����̴� "��"���� ��Ÿ���� ����
	bool EachInputCheck = false;			// �̵� Input�� �־����� �ִϸ��̼��� ���� (�� Object ����)
	bool ZInputCheck = false;				// Z Input�� �־����� �ִϸ��̼� �ѱ��� ����.
	
private:
};