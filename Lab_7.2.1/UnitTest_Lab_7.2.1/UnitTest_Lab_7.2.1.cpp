#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2.1/Lab_7.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab721
{
	TEST_CLASS(UnitTestLab721)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			list<int> arr;
			arr = { 5, -3, 17, 8, -10, 25, 0, -99, 13, 25 };
			Assert::AreEqual(93, count(arr, 10), 0.0001);
		}
	};
}
