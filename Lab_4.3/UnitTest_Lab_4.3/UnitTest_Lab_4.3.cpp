#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.3/Array.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab43
{
	TEST_CLASS(UnitTestLab43)
	{
	public:
		
		TEST_METHOD(TestMethod1)
        {
            // Створюємо два масиви
            Array arr1(5, 1);  // Масив з 5 елементів, заповнений 1
            Array arr2(5, 2);  // Масив з 5 елементів, заповнений 2

            // Очікуємо, що після додавання arr2 до arr1, всі елементи будуть рівні 3
            arr1.add(arr2);

            // Перевірка
            for (int i = 0; i < 5; ++i) {
                assert(arr1[i] == 3);  // Перевіряємо, що всі елементи масиву рівні 3
            }
        }
	};
}
