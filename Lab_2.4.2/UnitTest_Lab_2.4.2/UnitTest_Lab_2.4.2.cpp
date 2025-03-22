#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.4.2/Money.cpp"
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab242
{
    TEST_CLASS(UnitTestLab242)
    {
    public:

        TEST_METHOD(TestMethod1)  // Тест для числа 0,22
        {
            // Створення об'єкта з числом
            Money money(2, 4);
            string result = money.toString();
            // Перевірка, що результат співпадає з очікуваним
            Assert::AreEqual(result, string("нуль гривень , сорок чотири сотих"));
        }

        TEST_METHOD(TestMethod2)  // Тест для числа 99,99
        {
            Money money(4, 9);
            string result = money.toString();
            Assert::AreEqual(result, string("дев’яносто дев’ять гривень , дев’яносто дев’ять сотих"));
        }

        TEST_METHOD(TestMethod3)  // Тест для числа 333,33
        {
            Money money(5, 3);
            string result = money.toString();
            Assert::AreEqual(result, string("триста тридцять три гривень , тридцять три сотих"));
        }
    };
}
