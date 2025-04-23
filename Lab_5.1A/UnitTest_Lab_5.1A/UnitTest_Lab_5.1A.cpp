#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1A/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51A
{
	TEST_CLASS(UnitTestLab51A)
	{
	public:
		
        // Тест для префіксного інкременту
        TEST_METHOD(TestPreIncrement)
        {
            Money money(100, 5);  // Номінал 100, кількість купюр 5
            ++money;  // Префіксний інкремент
            Assert::AreEqual(money.GetFirst(), 101u);  // Перевіряємо, чи first збільшився на 1
                                                       // суфікс u дозволяє компілятору правильно зрозуміти тип unsigned int.
        }

        // Тест для префіксного декременту
        TEST_METHOD(TestPreDecrement)
        {
            Money money(100, 5);  // Номінал 100, кількість купюр 5
            --money;  // Префіксний декремент
            Assert::AreEqual(money.GetFirst(), 99u);  // Перевіряємо, чи first зменшився на 1
        }
	};
}
