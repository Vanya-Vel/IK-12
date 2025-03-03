#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1.3/Point.cpp"
#include "../Lab_1.3/Lab_1.3.cpp"

#include <string>
#include <sstream> // підключаємо бібліотеку, яка описує літерні потоки

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab13
{
	TEST_CLASS(UnitTestLab13)
	{
	public:
		
		TEST_METHOD(TestMethod_Num_8)
		{
			string as;
			as = "visim ";
			Point a;
			Assert::AreEqual(as, a.ToNumeral(8));
		}
		TEST_METHOD(TestMethod_Num_Error)
		{
			string bs;
			bs = "error";
			Point b;
			Assert::AreEqual(bs, b.ToNumeral(-5));
		}
	};
}
