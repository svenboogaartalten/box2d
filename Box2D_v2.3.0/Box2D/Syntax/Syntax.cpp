// Syntax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "InheritanceTest.h"
#include "OperatorOverloadingTest.h"
#include "PreprocessorTest.h"
#include "RockPaperScissor.h"
#include <vector>
#include <algorithm>
#include <csignal>

//custom signal handler
//can be tested with ctrl+v
void signalHandler(int signum) {
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	printf("something");
	// cleanup and close up stuff here  
	// terminate program  

	exit(signum);
}


int main()
{
	std::vector<TestBase*> tests;

	tests.push_back(new InheritanceTest());
	tests.push_back(new OperatorOverloadingTest());
	tests.push_back(new PreprocessorTest());


	signal(SIGFPE, signalHandler);
	signal(SIGINT, signalHandler);
	for (TestBase* var : tests)
	{
		var->RunTest();
	}
	int x = 0;
	std::cin >> x;
	if (x == 0)
	{
		raise(SIGINT);
	}
	RockPaperScissor game;
	game.Run();
	

	//ask the user to pressa key to continue
	system("pause");
	return 0;
}

