#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4.5/Dollar.h"
#include "../Lab_4.5/Currency.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab45
{
	TEST_CLASS(UnitTestLab45)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			{
				double n = 10;

				// Створення об'єкта долара
				Currency* dollar = new Dollar();

				// Виклик методу Exchange для перерахунку в гривні
				double result = dollar->Exchange(n);  // Оскільки курс долара задано як статичний, використовується без створення об'єкта

				// Порівняння з очікуваним результатом
				double expected = n * Dollar::GetCourse();  // Використовуємо геттер для отримання курсу долара
				Assert::AreEqual(expected, result);
			}

		}
	};
}
