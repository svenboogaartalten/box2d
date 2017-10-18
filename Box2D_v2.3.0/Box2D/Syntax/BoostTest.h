#pragma once
#include "TestBase.h"
#include <boost/lambda/lambda.hpp>

class BoostTest : public TestBase
{
public:
	BoostTest();
	~BoostTest();

	// Inherited via TestBase
	virtual void RunTest() override;
};

