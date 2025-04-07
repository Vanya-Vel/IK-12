#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3G/Functions.cpp"
#include "../Lab_3.3G/Object.cpp"
#include "../Lab_3.3G/Money.cpp"
#include "../Lab_3.3G/Bankomat.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33G
{
	TEST_CLASS(UnitTestLab33G)
	{
	public:
		
		TEST_METHOD(TestMethod_Count)
		{

			Functions atm, atm1;

			Assert::AreEqual(Object::Count(), 8u); // Очікуємо 3, u — для unsigned int
		}
	};
}
