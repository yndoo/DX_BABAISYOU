#pragma once
#include <EngineCore/EngineRenderTarget.h>

// ∆‰¿ÃµÂ æ∆øÙ ¿Ã∆Â∆Æ
class FadeOutEffect : public UEffect
{
public:
	FadeOutEffect();
	~FadeOutEffect();

	FadeOutEffect(const FadeOutEffect& _Other) = delete;
	FadeOutEffect(FadeOutEffect&& _Other) noexcept = delete;
	FadeOutEffect& operator=(const FadeOutEffect& _Other) = delete;
	FadeOutEffect& operator=(FadeOutEffect&& _Other) noexcept = delete;
	void EffectON();
	void EffectOff();
	void SetEffect(bool _Triger);

protected:
	void Init() override;
	void Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget) override;


private:
	std::shared_ptr<UEngineRenderTarget> CopyTarget;

};