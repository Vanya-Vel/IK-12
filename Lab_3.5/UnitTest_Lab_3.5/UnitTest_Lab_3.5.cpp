#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.5/Decimal.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab35
{
	TEST_CLASS(UnitTestLab35)
	{
	public:
		
		TEST_METHOD(TestMethod_rangeCheck_T)
		{
			Decimal a("12345");

			// Тест: коректний індекс (має повернути true)
			bool result = a.rangeCheck(2);
			Assert::IsTrue(result, L"rangeCheck має повернути true для індексу 2");
		}

		TEST_METHOD(TestMethod_rangeCheck_F)
		{
			Decimal a("12345");

			// Тест: коректний індекс (має повернути true)
			bool result = a.rangeCheck(5);
			Assert::IsTrue(!result, L"rangeCheck має повернути false для індексу ");
		}
	};
}
