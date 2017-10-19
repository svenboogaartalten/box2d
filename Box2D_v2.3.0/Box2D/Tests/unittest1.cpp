#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AreEqual)
		{
			// TODO: Your test code here
			Assert::AreEqual(1, 1);
		}


		TEST_METHOD(AreNotEqual)
		{
			// TODO: Your test code here
			Assert::AreNotEqual(1, 2);
		}

		TEST_METHOD(IsTrue)
		{
			// TODO: Your test code here
			Assert::IsTrue(1 == (2 / 2));
		}

		TEST_METHOD(IsNull)
		{
			int * p = NULL;
			Assert::IsNull(p);

		}

		TEST_METHOD(AreSameReference)
		{
			int x = 5;
			int & p = x;
			int & d = x;
			Assert::AreSame(p, d);

		}

	};
}
