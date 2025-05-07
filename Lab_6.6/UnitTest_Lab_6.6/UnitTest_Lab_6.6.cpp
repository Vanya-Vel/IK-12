#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.6/Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab66
{
	TEST_CLASS(UnitTestLab66)
	{
	public:
		
        TEST_METHOD(TestMethodPlus)
        {
            // Створюємо масив, заповнений значеннями 5
            Array<int, 4> a(5);

            // Додаємо 10 до кожного елемента масиву
            Array<int, 4> d = a + 10;

            // Перевіряємо, чи всі елементи масиву d дорівнюють 15 (5 + 10)
            for (int i = 0; i < 4; ++i) {
                Assert::AreEqual(15, d[i]);
            }
        }
	};
}
