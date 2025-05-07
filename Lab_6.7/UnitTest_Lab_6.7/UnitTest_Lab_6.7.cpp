#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.7/Lab_6.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab67
{
	TEST_CLASS(UnitTestLab67)
	{
	public:
		
		TEST_METHOD(TestEraseIf)
		{
			int input[] = { 1, -3, 4, -2, 5 };
			int expected[] = { 1, 4, 5 };
			int result[5];

			Negative<int> predicate;
			int newSize = erase_if(input, input + 5, result, predicate);

			Assert::AreEqual(3, newSize);
			for (int i = 0; i < newSize; i++)
			{
				Assert::AreEqual(expected[i], result[i]);
			}
		}
	};
}
