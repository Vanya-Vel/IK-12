#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1/Lab_6.1.cpp"
#include "../Lab_6.1/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab61
{
	TEST_CLASS(UnitTestLab61)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            // Оголошення масиву розміру 11
            TArray a = new Array::value_type[11];

            // Заповнення масиву значеннями від -5 до 5
            for (int i = 0; i < 11; ++i)
                a[i] = i - 5;  // Значення будуть: -5, -4, ..., 5

            // Викликаємо функцію MultiplyByMinimum
            Array result = Array::MultiplyByMinimum(a, 11);

            // Мінімальне значення в масиві = -5
            // Масив до множення: [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]

            // Оскільки мінімальний елемент = -5, множимо кожен елемент на -5
            // Очікуваний результат: [25, 20, 15, 10, 5, 0, -5, -10, -15, -20, -25]

            // Перевірка для кожного елемента
            Assert::AreEqual(25.0, result[0], L"1-й елемент не відповідає очікуваному!");
            Assert::AreEqual(20.0, result[1], L"2-й елемент не відповідає очікуваному!");
            Assert::AreEqual(15.0, result[2], L"3-й елемент не відповідає очікуваному!");
            Assert::AreEqual(10.0, result[3], L"4-й елемент не відповідає очікуваному!");
            Assert::AreEqual(5.0, result[4], L"5-й елемент не відповідає очікуваному!");
            Assert::AreEqual(0.0, result[5], L"6-й елемент не відповідає очікуваному!");
            Assert::AreEqual(-5.0, result[6], L"7-й елемент не відповідає очікуваному!");
            Assert::AreEqual(-10.0, result[7], L"8-й елемент не відповідає очікуваному!");
            Assert::AreEqual(-15.0, result[8], L"9-й елемент не відповідає очікуваному!");
            Assert::AreEqual(-20.0, result[9], L"10-й елемент не відповідає очікуваному!");
            Assert::AreEqual(-25.0, result[10], L"11-й елемент не відповідає очікуваному!");

            // Очистка пам'яті
            delete[] a;
        }
	};
}
