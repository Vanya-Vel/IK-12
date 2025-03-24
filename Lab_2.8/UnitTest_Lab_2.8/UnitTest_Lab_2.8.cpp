#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.8/Bankomat.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab28
{
	TEST_CLASS(UnitTestLab28)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            // Вхідне значення
            double total = 374.5;

            // Ожиданий результат
            std::string expected = "триста сімдесят чотири гривень , п’ятдесят копійок";

            // Створюємо об'єкт Money
            Bankomat::Money atmMoney;

            // Отримуємо текстове представлення числа
            std::string result = atmMoney.numberToWords(total);

            // Перевіряємо, чи відповідає результат очікуваному
            Assert::AreEqual(expected, result);
        }
	};
}
