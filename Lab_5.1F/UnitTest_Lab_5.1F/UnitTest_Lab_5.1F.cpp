#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1F/Pair.cpp"
#include "../Lab_5.1F/Rectangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51F
{
	TEST_CLASS(UnitTestLab51F)
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
