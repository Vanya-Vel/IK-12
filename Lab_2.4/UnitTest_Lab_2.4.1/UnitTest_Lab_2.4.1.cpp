#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.4/Vector.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab241
{
	TEST_CLASS(UnitTestLab241)
	{
	public:
		
		TEST_METHOD(TestMethod_Summa)
		{
			Vector v(5, 9);
			Assert::AreEqual(v.summa(), 45);
		}

		TEST_METHOD(TestMethod_Norm_F)
		{
			Vector v1(4, 7);  // Вектор з 4 елементами, кожен рівний 7
			Vector v2(2, 6);  // Вектор з 2 елементами, кожен рівний 6

			// Очікуємо, що їхні норми не будуть рівними
			Assert::AreNotEqual(v1.NormVector(), v2.NormVector(), L"Норми векторів мають бути не рівні");
		}

	};
}
