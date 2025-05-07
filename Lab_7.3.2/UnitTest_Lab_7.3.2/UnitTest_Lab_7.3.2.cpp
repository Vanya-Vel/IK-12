#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.2/Lab_7.3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab732
{
	TEST_CLASS(UnitTestLab732)
	{
	public:
		
		TEST_METHOD(AllOnce)
		{
			std::string input = "a + b - c * d / e";
			Assert::AreEqual(4, countUniqueOperators(input));
		}

		TEST_METHOD(SomeRepeated)
		{
			std::string input = "+ + - * /";
			Assert::AreEqual(3, countUniqueOperators(input)); // '+' — 2 рази
		}

		TEST_METHOD(None)
		{
			std::string input = "abcdefg123";
			Assert::AreEqual(0, countUniqueOperators(input));
		}
	};
}
