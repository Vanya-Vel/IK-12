#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1E/Functions.h"
#include "../Lab_5.1E/Object.cpp"
#include "../Lab_5.1E/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51E
{
	TEST_CLASS(UnitTestLab51E)
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
