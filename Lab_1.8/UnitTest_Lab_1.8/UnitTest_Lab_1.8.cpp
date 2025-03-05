#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.8/Bankomat.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab18
{
	TEST_CLASS(UnitTestLab18)
	{
	public:
		
		TEST_METHOD(TestMethod_Init)
		{
			Bankomat b;
			b.Init("000", 100, 1000);  // Ініціалізація банкомату

			// Перевірка, чи зміни застосувались
			Assert::AreEqual(100.0, b.getMinWithdrawalAmount());  // Перевіряємо мінімальну суму
			Assert::AreEqual(1000.0, b.getMaxWithdrawalAmount());  // Перевіряємо максимальну суму
		}
	};
}
