#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.1/Lab_1.1.cpp"
#include "../Lab_1.1/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab11
{
	TEST_CLASS(UnitTestLab11)
	{
	public:
		
		TEST_METHOD(Test_Init_DN_T)
		{
			int Denom = 2;
			int NumOfDenom = 7;
			Money m;
			bool result = m.Init(Denom, NumOfDenom);
			Assert::IsTrue(result);  // Перевіряємо, чи результат ініціалізації успішний - так

		}

		TEST_METHOD(Test_Init_DN_F)
		{
			int Denom = 5;
			int NumOfDenom = 0;
			Money n;
			bool result = n.Init(Denom, NumOfDenom);
			Assert::IsTrue(!result);  // Перевіряємо, чи результат ініціалізації успішний - ні
		}
	};
}
