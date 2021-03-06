// BoostTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define BOOST_TEST_MODULE somename
#include <boost/test/included/unit_test.hpp>
namespace boostTest {

	BOOST_AUTO_TEST_CASE(BoostRequire)
	{
		
		/*This approach uses the BOOST_REQUIRE tool, is similar to approach BOOST_CHECK,
		except that after displaying the error, an exception is thrown, to be caught
		by the Unit Test Framework.This approach is suitable when writing an explicit
		test program, and the error would be so severe as to make further testing 
		impractical.BOOST_REQUIRE differs from the C++ Standard Library's assert() 
		macro in that it is always generated, and channels error detection into the 
		uniform Unit Test Framework reporting procedure.*/

		BOOST_REQUIRE(2 + 2 == 4);
	}


	BOOST_AUTO_TEST_CASE(BoostCase)
	{
		float x = 9.5f;

		/*This approach uses the BOOST_CHECK tool, which displays an error
		message(by default on std::cout) that includes the expression that 
		failed, the source file name, and the source file line number.It 
		also increments the error count.At program termination, the error 
		count will be displayed automatically by the Unit Test Framework.*/
		BOOST_CHECK(x != 0.0f);

		/*This approach is most attractive for checking equality of two variables, 
		since in case of error it shows mismatched values.*/
		BOOST_CHECK_EQUAL((int)x, 9);


		BOOST_CHECK_CLOSE(x, 9.5f, 0.0001f); // Checks differ no more then 0.0001%
		


	}

	BOOST_AUTO_TEST_CASE(BoostCaseTwo)
	{
		int x = 9;


		/*This approach uses the BOOST_CHECK_EQUAL tool and functionally is
		similar to BOOST_CHECK This approach is most attractive for checking 
		equality of two variables, since in case of error it shows mismatched values.*/
		BOOST_CHECK_EQUAL((int)x, 9);


	}

	
}