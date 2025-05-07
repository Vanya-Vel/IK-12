#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2.2/Lab_7.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab722
{
	TEST_CLASS(UnitTestLab722)
	{
	public:
		
        TEST_METHOD(TestSumOfPositiveElements)
        {
            // Вхідні фіксовані дані
            list<int> testList = { 5, -3, 17, 8, -10, 25, 0, -99, 13, 25 };

            // Очікувана сума додатних: 5 + 17 + 8 + 25 + 13 + 25 = 93
            int expectedSum = 93;

            // Фактичний результат
            int actualSum = sumOfPositiveElements(testList);

            // Перевірка результату
            Assert::AreEqual(expectedSum, actualSum);
        }
	};
}
