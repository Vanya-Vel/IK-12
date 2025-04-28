#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1D/Functions.cpp"
#include "../Lab_5.1D/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51D
{
	TEST_CLASS(UnitTestLab51D)
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
