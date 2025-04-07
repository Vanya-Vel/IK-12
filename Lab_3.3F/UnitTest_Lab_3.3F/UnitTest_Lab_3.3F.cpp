#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3F/Functions.cpp"
#include "../Lab_3.3F/Bankomat.cpp"
#include "../Lab_3.3F/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33F
{
	TEST_CLASS(UnitTestLab33F)
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
