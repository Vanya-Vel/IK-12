#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1B/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51B
{
	TEST_CLASS(UnitTestLab51B)
	{
	public:
		
		TEST_METHOD(TestMethod_Distanse)
		{
			Point p1, p2;
			p1 = Point(4, 5);
			p2 = Point(8, 10);
			Assert::AreEqual(p1.distanceFromXtoY(p2), 6.4);
		}
	};
}
