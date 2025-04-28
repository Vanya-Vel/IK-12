#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1G/Pair.cpp"
#include "../Lab_5.1G/pFunctions.h"
#include "../Lab_5.1G/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51G
{
	TEST_CLASS(UnitTestLab51G)
	{
	public:
		
		TEST_METHOD(TestMethod_Count)
		{

			Pair p, p1(10, 9);
			pFunctions pFunc(8, 1);

			Assert::AreEqual(Object::Count(), 3u); // Очікуємо 3, u — для unsigned int
		}
	};
}
