#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.1/ArithmeticProg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab41
{
	TEST_CLASS(UnitTestLab41)
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
