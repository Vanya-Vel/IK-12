#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1H/Functions.cpp"
#include "../Lab_5.1H/Bankomat.cpp"
#include "../Lab_5.1H/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51H
{
	TEST_CLASS(UnitTestLab51H)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            // Вхідне значення
            double total = 374.5;

            // Ожиданий результат
            std::string expected = "триста сімдесят чотири гривень , п’ятдесят копійок";

            // Створюємо об'єкт Money
            Functions atmMoney;

            // Отримуємо текстове представлення числа
            std::string result = atmMoney.numberToWords(total);

            // Перевіряємо, чи відповідає результат очікуваному
            Assert::AreEqual(expected, result);
        }
	};
}
