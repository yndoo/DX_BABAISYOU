#include "PreCompile.h"

#include <BABAISYOU/BABAISYOUCore.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UEngineCore::Start<UBABAISYOUCore>(hInstance);
}