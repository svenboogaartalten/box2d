// Syntax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "InheritanceTest.h"
#include "OperatorOverloadingTest.h"
#include "PreprocessorTest.h"
#include <vector>
#include <algorithm>


int main()
{
	std::vector<TestBase*> tests;

	tests.push_back(new InheritanceTest());
	tests.push_back(new OperatorOverloadingTest());
	tests.push_back(new PreprocessorTest());



	for (TestBase* var : tests)
	{
		var->RunTest();
	}



	//ask the user to pressa key to continue
	system("pause");
    return 0;
}

