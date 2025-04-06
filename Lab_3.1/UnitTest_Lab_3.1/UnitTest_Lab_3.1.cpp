#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.1/Pair.cpp"
#include "../Lab_3.1/Rectangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab31
{
	TEST_CLASS(UnitTestLab31)
	{
	public:
		
		TEST_METHOD(TestGetArea)
		{
			// Створення об'єкта Pair і ініціалізація значень сторін прямокутника
			Pair sides(5, 10);

			// Створення об'єкта прямокутника та ініціалізація його сторонами
			Rectangle rect(sides);

			// Перевірка площі прямокутника (5 * 10 = 50)
			Assert::AreEqual(rect.getArea(), 50);
		}
	};
}
