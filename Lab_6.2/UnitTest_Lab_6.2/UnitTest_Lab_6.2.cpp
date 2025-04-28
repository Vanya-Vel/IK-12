#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2/Rand.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab62
{
	TEST_CLASS(UnitTestLab62)
	{
	public:

        TEST_METHOD(TestAdd)
        {
            // Створення об'єкта Rand з фіксованим розміром масиву
            Rand r(5);

            // Додавання кількох пар (x, p) для тестування
            r.add(1.0, 0.2);  // (x1, p1)
            r.add(2.0, 0.4);  // (x2, p2)
            r.add(3.0, 0.4);  // (x3, p3)

            // Очікуване математичне очікування
            double expected_mean = 1.0 * 0.2 + 2.0 * 0.4 + 3.0 * 0.4;  // 0.2 + 0.8 + 1.2 = 2.2

            // Перевірка, чи метод mean() повертає правильне значення
            Assert::AreEqual(expected_mean, r.mean(), L"Математичне очікування обчислено неправильно.");
        }
	};
}
