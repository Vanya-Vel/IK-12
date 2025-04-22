#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.2/ArithmeticProg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab42
{
	TEST_CLASS(UnitTestLab42)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ABase* a = new ArithmeticProg(1.0, 2.0);

			double expected = 25.0;
			double actual = a->sum_progression(5);

			Assert::AreEqual(expected, actual);

			delete a;
		}
	};
}
