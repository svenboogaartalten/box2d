#pragma once
#include "TestBase.h"
class AsyncTest :
	public TestBase
{
public:
	void CalledFromAsync();
	AsyncTest();
	~AsyncTest();

	// Inherited via TestBase
	virtual void RunTest() override;
};

