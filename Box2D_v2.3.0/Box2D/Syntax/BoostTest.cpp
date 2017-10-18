#include "stdafx.h"
#include "BoostTest.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/foreach.hpp>
#include <map>
#include <string>
#include "InheritanceTest.h"
#include "OperatorOverloadingTest.h"

BoostTest::BoostTest()
{
}


BoostTest::~BoostTest()
{
}

void BoostTest::RunTest()
{
	std::string hello("Hello, world!");
	
	BOOST_FOREACH(char ch, hello)
	{
		std::cout << ch << "   ";
	}
}
