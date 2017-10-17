#include "stdafx.h"
#include "PreprocessorTest.h"
#define SOMEVAR "HALLO"

PreprocessorTest::PreprocessorTest()
{
}


PreprocessorTest::~PreprocessorTest()
{
}

void PreprocessorTest::RunTest()
{
	std::cout << std::endl << std::endl;
	std::cout << "preprocessor test" << std::endl;
	std::cout << "Value of __LINE__ : " << __LINE__ << std::endl;
	std::cout << "Value of __FILE__ : " << __FILE__ << std::endl;
	std::cout << "Value of __DATE__ : " << __DATE__ << std::endl;
	std::cout << "Value of __TIME__ : " << __TIME__ << std::endl;
	std::cout << "Value of SOMEVAR : " << SOMEVAR << std::endl;
}
