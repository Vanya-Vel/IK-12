#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.1/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab21
{
    TEST_CLASS(UnitTestLab21)
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

        // Тест для постфіксного інкременту
        TEST_METHOD(TestPostIncrement)
        {
            Money money(100, 5);  // Номінал 100, кількість купюр 5
            Money temp = money++;  // Постфіксний інкремент
            Assert::AreEqual(temp.GetFirst(), 100u);  // Перевіряємо копію до зміни
            Assert::AreEqual(temp.GetSecond(), 5u);  // Перевіряємо копію до зміни
            Assert::AreEqual(money.GetFirst(), 100u);  // Перевіряємо після зміни
            Assert::AreEqual(money.GetSecond(), 6u);  // Перевіряємо, чи second збільшився на 1
        }

        // Тест для постфіксного декременту
        TEST_METHOD(TestPostDecrement)
        {
            Money money(100, 5);  // Номінал 100, кількість купюр 5
            Money temp = money--;  // Постфіксний декремент
            Assert::AreEqual(temp.GetFirst(), 100u);  // Перевіряємо копію до зміни
            Assert::AreEqual(temp.GetSecond(), 5u);  // Перевіряємо копію до зміни
            Assert::AreEqual(money.GetFirst(), 100u);  // Перевіряємо після зміни
            Assert::AreEqual(money.GetSecond(), 4u);  // Перевіряємо, чи second зменшився на 1
        }
    };
}
