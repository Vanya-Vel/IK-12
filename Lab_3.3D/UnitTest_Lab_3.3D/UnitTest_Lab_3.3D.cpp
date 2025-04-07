#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3D/Pair.cpp"
#include "../Lab_3.3D/Rectangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33D
{
	TEST_CLASS(UnitTestLab33D)
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
