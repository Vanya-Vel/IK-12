#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.2/Lab_1.2.cpp"
#include "../Lab_1.2/Circle.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab12
{
	TEST_CLASS(UnitTestLab12)
	{
	public:
			TEST_METHOD(Test_Init_R_T)
			{
				int x = 2;
				int y = 7;
				double radius = 9;

				Circle m;
				bool result = m.Init(x, y, radius);
				Assert::IsTrue(result);  // Перевіряємо, чи результат ініціалізації успішний - так

			}

			TEST_METHOD(Test_Init_R_F)
			{
				int x = 2;
				int y = 7;
				double radius = 0;

				Circle n;
				bool result = n.Init(x, y, radius);
				Assert::IsTrue(!result);  // Перевіряємо, чи результат ініціалізації успішний - ні
			}
	};
}
