#pragma once
#include <EngineCore/EngineCore.h>

// Ό³Έν :
class UBABAISYOUCore : public UserCore
{
public:
	// constrcuter destructer
	UBABAISYOUCore();
	~UBABAISYOUCore();

	// delete Function
	UBABAISYOUCore(const UBABAISYOUCore& _Other) = delete;
	UBABAISYOUCore(UBABAISYOUCore&& _Other) noexcept = delete;
	UBABAISYOUCore& operator=(const UBABAISYOUCore& _Other) = delete;
	UBABAISYOUCore& operator=(UBABAISYOUCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

