#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>  // Для sqrt та pow
#include "../Lab_3.3A/Functions.cpp"
#include "../Lab_3.3A/Point.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33A
{
    TEST_CLASS(UnitTestLab33A)
    {
    public:

        TEST_METHOD(TestMethod_Distance)
        {
            Functions p1(4, 5);    // Об'єкти класу Functions для точок
            Functions p2(8, 10);

            // Обчислення відстані
            double expected = sqrt(pow(8 - 4, 2) + pow(10 - 5, 2));
            double roundedExpected = round(expected * 100.0) / 100.0;  // Округлення до двох знаків

            // Перевірка чи відстань між точками збігається з очікуваним результатом
            double calculatedDistance = p1.distanceFromXtoY(p2);  // Отримуємо відстань

            // Перевіряємо, чи обчислене значення відстані відповідає очікуваному
            Assert::AreEqual(calculatedDistance, roundedExpected, 0.01);  // Третій параметр дозволяє порівнювати з точністю до 0.01
        }
    };
}
