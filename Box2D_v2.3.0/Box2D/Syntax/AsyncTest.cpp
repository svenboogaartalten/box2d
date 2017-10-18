#include "stdafx.h"
#include "AsyncTest.h"
#include <future>
#include <iostream>

void CalledFromAsync()
{
	std::cout << "Async call" << std::endl;
}

AsyncTest::AsyncTest()
{
}


AsyncTest::~AsyncTest()
{
}

void AsyncTest::RunTest()
{
	auto someversion = __cplusplus;

	std::cout << someversion;
	
	
}
