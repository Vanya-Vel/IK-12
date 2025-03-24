#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.7/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab27
{
	TEST_CLASS(UnitTestLab27)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            // Вхідне значення
            double total = 374.5;

            // Ожиданий результат
            std::string expected = "триста сімдесят чотири гривень , п’ятдесят копійок";

            // Створюємо об'єкт Money
            Money atmMoney;

            // Отримуємо текстове представлення числа
            std::string result = atmMoney.numberToWords(total);

            // Перевіряємо, чи відповідає результат очікуваному
            Assert::AreEqual(expected, result);
        }
	};
}
