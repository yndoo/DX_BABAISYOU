#include "PreCompile.h"
#include "FadeOutEffect.h"

FadeOutEffect::FadeOutEffect()
{
}

FadeOutEffect::~FadeOutEffect()
{
}
void FadeOutEffect::Init()
{
	SetMaterial("CircleFadeOUT");

	CopyTarget = UEngineRenderTarget::Create();
	
	float4 Scale = GEngine->EngineWindow.GetWindowScale();
	CopyTarget->CreateTexture(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, Scale, float4::Zero);
}

void FadeOutEffect::Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget)
{
	CopyTarget->Copy(EffectTarget);
	EffectTarget->Clear();
	EffectTarget->Setting();

	Resources->SettingTexture("Image", CopyTarget->GetTexture(), "POINT");

	Render(0.0f);

}

void FadeOutEffect::EffectON()
{
	Active(true);
}

void FadeOutEffect::EffectOff()
{
	Active(false);
}

void FadeOutEffect::SetEffect(bool _Triger)
{
	Active(_Triger);
}