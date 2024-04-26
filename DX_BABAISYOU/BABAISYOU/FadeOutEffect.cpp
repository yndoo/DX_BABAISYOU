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