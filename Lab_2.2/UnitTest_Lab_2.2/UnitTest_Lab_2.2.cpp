#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.2/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab22
{
	TEST_CLASS(UnitTestLab22)
	{
	public:

		TEST_METHOD(TestMatr1PlusMatr2)
		{
			// Створюємо дві матриці 3x3
			Matrix m1(3, 3);
			Matrix m2(3, 3);

			// Заповнюємо першу матрицю значеннями
			m1.SetElement(0, 0, 1);
			m1.SetElement(0, 1, 2);
			m1.SetElement(0, 2, 3);
			m1.SetElement(1, 0, 4);
			m1.SetElement(1, 1, 5);
			m1.SetElement(1, 2, 6);
			m1.SetElement(2, 0, 7);
			m1.SetElement(2, 1, 8);
			m1.SetElement(2, 2, 9);

			// Заповнюємо другу матрицю значеннями
			m2.SetElement(0, 0, 9);
			m2.SetElement(0, 1, 8);
			m2.SetElement(0, 2, 7);
			m2.SetElement(1, 0, 6);
			m2.SetElement(1, 1, 5);
			m2.SetElement(1, 2, 4);
			m2.SetElement(2, 0, 3);
			m2.SetElement(2, 1, 2);
			m2.SetElement(2, 2, 1);

			// Додаємо дві матриці
			Matrix result = m1 + m2;

			// Перевіряємо результат додавання
			Assert::AreEqual(result.GetElement(0, 0), 10);  // 1 + 9
			Assert::AreEqual(result.GetElement(0, 1), 10);  // 2 + 8
			Assert::AreEqual(result.GetElement(0, 2), 10);  // 3 + 7
			Assert::AreEqual(result.GetElement(1, 0), 10);  // 4 + 6
			Assert::AreEqual(result.GetElement(1, 1), 10);  // 5 + 5
			Assert::AreEqual(result.GetElement(1, 2), 10);  // 6 + 4
			Assert::AreEqual(result.GetElement(2, 0), 10);  // 7 + 3
			Assert::AreEqual(result.GetElement(2, 1), 10);  // 8 + 2
			Assert::AreEqual(result.GetElement(2, 2), 10);  // 9 + 1
		}

		TEST_METHOD(TestMatr1MinusMatr2)
		{
			// Створюємо дві матриці 3x3
			Matrix m1(3, 3);
			Matrix m2(3, 3);

			// Заповнюємо першу матрицю значеннями
			m1.SetElement(0, 0, 1);
			m1.SetElement(0, 1, 2);
			m1.SetElement(0, 2, 3);
			m1.SetElement(1, 0, 4);
			m1.SetElement(1, 1, 5);
			m1.SetElement(1, 2, 6);
			m1.SetElement(2, 0, 7);
			m1.SetElement(2, 1, 8);
			m1.SetElement(2, 2, 9);

			// Заповнюємо другу матрицю значеннями
			m2.SetElement(0, 0, 9);
			m2.SetElement(0, 1, 8);
			m2.SetElement(0, 2, 7);
			m2.SetElement(1, 0, 6);
			m2.SetElement(1, 1, 5);
			m2.SetElement(1, 2, 4);
			m2.SetElement(2, 0, 3);
			m2.SetElement(2, 1, 2);
			m2.SetElement(2, 2, 1);

			// Віднімаємо дві матриці
			Matrix result = m1 - m2;

			// Перевіряємо результат віднімання
			Assert::AreEqual(result.GetElement(0, 0), -8);  // 1 - 9
			Assert::AreEqual(result.GetElement(0, 1), -6);  // 2 - 8
			Assert::AreEqual(result.GetElement(0, 2), -4);  // 3 - 7
			Assert::AreEqual(result.GetElement(1, 0), -2);  // 4 - 6
			Assert::AreEqual(result.GetElement(1, 1), 0);   // 5 - 5
			Assert::AreEqual(result.GetElement(1, 2), 2);   // 6 - 4
			Assert::AreEqual(result.GetElement(2, 0), 4);   // 7 - 3
			Assert::AreEqual(result.GetElement(2, 1), 6);   // 8 - 2
			Assert::AreEqual(result.GetElement(2, 2), 8);   // 9 - 1
		}
	};
}
