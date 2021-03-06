// Syntax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "InheritanceTest.h"
#include "OperatorOverloadingTest.h"
#include "PreprocessorTest.h"
#include "RockPaperScissor.h"
#include "RockPaperScissor.h"
#include "BoostTest.h"
#include "AsyncTest.h"
#include <vector>
#include <algorithm>
#include <csignal>



int main()
{
	std::vector<TestBase*> tests;

	tests.push_back(new InheritanceTest());
	tests.push_back(new OperatorOverloadingTest());
	tests.push_back(new PreprocessorTest());
	tests.push_back(new BoostTest());
	tests.push_back(new AsyncTest());

	
	for (TestBase* var : tests)
	{
		var->RunTest();
		std::cout << std::endl << " -------" << std::endl << std::endl;
	}
	
	//RockPaperScissor game;
	//game.Run();
	

	//ask the user to pressa key to continue
	system("pause");
	return 0;
}

