#pragma once
#include "TestBase.h"
class OperatorOverloadingTest :
	public TestBase
{
public:
	OperatorOverloadingTest();
	~OperatorOverloadingTest();

	// Inherited via TestBase
	virtual void RunTest() override;
};

