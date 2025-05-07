#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.1/Lab_7.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab731
{
	TEST_CLASS(UnitTestLab731)
	{
	public:
		
		TEST_METHOD(OnlyOnceEachOperator)
		{
			std::string input = "a + b - c * d / e";
			int expected = 4; // Кожен оператор один раз
			Assert::AreEqual(expected, countUniqueOperators(input));
		}

		TEST_METHOD(SomeOperatorsRepeated)
		{
			std::string input = "x + y + z - q * 2 / 1";
			int expected = 3; // '+': 2 рази (пропускаємо), інші — по 1
			Assert::AreEqual(3, countUniqueOperators(input));
		}

		TEST_METHOD(NoOperators)
		{
			std::string input = "abcdefg";
			int expected = 0;
			Assert::AreEqual(expected, countUniqueOperators(input));
		}
	};
}
