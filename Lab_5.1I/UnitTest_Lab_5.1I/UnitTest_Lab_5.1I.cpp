#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1I/Functions.cpp"
#include "../Lab_5.1I/Object.cpp"
#include "../Lab_5.1I/Money.cpp"
#include "../Lab_5.1I/Bankomat.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51I
{
	TEST_CLASS(UnitTestLab51I)
	{
	public:
		
		TEST_METHOD(TestMethod_Count)
		{

			Functions atm, atm1;

			Assert::AreEqual(Object::Count(), 4u); // Очікуємо 8, u — для unsigned int
		}
	};
}
