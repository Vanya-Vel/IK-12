#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.3E/Object.cpp"
#include "../Lab_3.3E/Pair.cpp"
#include "../Lab_3.3E/pFunctions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33E
{
	TEST_CLASS(UnitTestLab33E)
	{
	public:
		
		TEST_METHOD(TestMethod_Count)
		{

			Pair p, p1(10, 9);
			pFunctions pFunc(8, 1);

			Assert::AreEqual(Object::Count(), 3u); // Очікуємо 2, u — для unsigned int
		}
	};
}
