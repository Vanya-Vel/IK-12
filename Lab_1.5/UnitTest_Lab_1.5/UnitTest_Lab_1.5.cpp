#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.5/Rectangle.cpp"
#include "../Lab_1.5/Pair.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab15
{
	TEST_CLASS(UnitTestLab15)
	{
	public:

		TEST_METHOD(TestGetArea)
		{
			// Створення об'єкта Pair і ініціалізація значень сторін прямокутника
			Pair sides;
			sides.Init(5, 10);  // 5 та 10 - сторони прямокутника

			// Створення об'єкта прямокутника та ініціалізація його сторонами
			Rectangle rect;
			rect.Init(sides);

			// Перевірка площі прямокутника (5 * 10 = 50)
			Assert::AreEqual(rect.getArea(), 50);
		}
	};
}
