#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3C/Functions.cpp"
#include "../Lab_3.3C/Object.cpp"
#include "../Lab_3.3C/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33C
{
	TEST_CLASS(UnitTestLab33C)
	{
	public:
		
		TEST_METHOD(TestMethod_Count)
		{

			Functions::Reset(); // Скидаємо лічильник
			Functions p1(4, 5);
			Functions p2(9, 0);

			Assert::AreEqual(Functions::Count(), 2u); // Очікуємо 2, u — для unsigned int
		}
	};
}
