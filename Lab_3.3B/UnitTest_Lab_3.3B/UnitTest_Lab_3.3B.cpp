#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3B/Functions.cpp"
#include "../Lab_3.3B/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33B
{
	TEST_CLASS(UnitTestLab33B)
	{
	public:
		
		TEST_METHOD(TestMethod_Compare)
		{
			Functions p1(3, 7);
			Functions p2(2, 6);

			Assert::IsTrue(p1 > p2);
		}
	};
}
