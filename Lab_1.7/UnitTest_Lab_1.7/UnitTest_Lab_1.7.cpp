#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.7/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestLab17
{
	TEST_CLASS(UnitTestLab17)
	{
	public:
		
		TEST_METHOD(TestMethod_numberToWords)
        {
            double Number;
            Number = 20.25;
            Money m;

            // Використовуємо std::string для порівняння рядків
            string expected = "двадцять гривень , двадцять п’ять копійок";
            Assert::AreEqual(expected, m.numberToWords(Number));  // Порівнюємо два рядки типу std::string
        }
	};
}
