#pragma once
#include "TestBase.h"
class InheritanceTest :
	public TestBase
{
public:
	InheritanceTest();
	~InheritanceTest();

	// Inherited via TestBase
	virtual void RunTest() override;
};

