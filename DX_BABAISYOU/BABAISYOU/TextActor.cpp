#include "PreCompile.h"
#include "TextActor.h"
#include "ContentsConstValue.h"

TextActor::TextActor()
{
	Root = CreateDefaultSubObject<UDefaultSceneComponent>("RendererRoot");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::UI);
	Renderer->SetScale(FVector(36, 36));
}

TextActor::~TextActor()
{
}

void TextActor::BeginPlay()
{
	Super::BeginPlay();
	CreateAlphaAnimation();
}

void TextActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void TextActor::SetAnimation(std::string_view _Alpha)
{
	Renderer->ChangeAnimation(_Alpha);
}

void TextActor::CreateAlphaAnimation()
{
	Renderer->CreateAnimation("U", "U.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("N", "N.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("D", "D.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("O", "O.png", AnimationInterVec, { 0,1,2 }, true);

	Renderer->CreateAnimation("R", "R.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("E", "E.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("S", "S.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("T", "T.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("A", "A.png", AnimationInterVec, { 0,1,2 }, true);

	Renderer->CreateAnimation("B", "B.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("I", "I.png", AnimationInterVec, { 0,1,2 }, true);
	Renderer->CreateAnimation("Y", "Y.png", AnimationInterVec, { 0,1,2 }, true);

	Renderer->CreateAnimation("C", "Alphabet.png", AnimationInterVec, { 4, 4 + 14, 4 + 14 * 2 }, true);
	Renderer->CreateAnimation("G", "Alphabet.png", AnimationInterVec, { 12, 12 + 14, 12 + 14 * 2 }, true);
	Renderer->CreateAnimation("L", "Alphabet.png", AnimationInterVec, { 50, 50 + 14, 50 + 14 * 2 }, true);
}

void TextActor::SetRendererScale(FVector _Scale)
{
	Renderer->SetScale(_Scale);
}

void TextActor::SetRendererMulColor(FVector _Color)
{
	_Color.X = _Color.X / 255;
	_Color.Y = _Color.Y / 255;
	_Color.Z = _Color.Z / 255;
	Renderer->SetMulColor(_Color);
}