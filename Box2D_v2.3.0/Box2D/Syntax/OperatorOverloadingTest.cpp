#include "stdafx.h"
#include "OperatorOverloadingTest.h"
#include "OperatorOverloaded.h"

OperatorOverloadingTest::OperatorOverloadingTest()
{
}


OperatorOverloadingTest::~OperatorOverloadingTest()
{
}

void OperatorOverloadingTest::RunTest()
{
	std::cout << std::endl << std::endl;
	std::cout << "Operator overloading test" << std::endl;
	OperatorOverloaded myOperatorIsOverloaded(5);
	std::cout << "value of object one : " << myOperatorIsOverloaded.m_value << std::endl;
	
	OperatorOverloaded myOperatorIsAlsoOverloaded(5);
	std::cout << "value of object two : " << myOperatorIsOverloaded.m_value << std::endl;

	OperatorOverloaded imTheResult = myOperatorIsOverloaded + myOperatorIsAlsoOverloaded;
	std::cout << "value of object created with overloaded operator : " << imTheResult.m_value << std::endl;


}
