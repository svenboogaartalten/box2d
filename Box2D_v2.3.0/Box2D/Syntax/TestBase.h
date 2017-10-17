#pragma once
#include <iostream>


class TestBase
{
public:
	TestBase();
	~TestBase();
	virtual void RunTest() = 0;
};

