#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1.1/Lab_7.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab711
{
	TEST_CLASS(UnitTestLab711)
	{
	public:
		
        TEST_METHOD(TestMethod)
        {
            array<int, 100> arr = { 5, -3, 17, 8, -10, 25, 0, -99, 13, 25 };

            double maxIndex = findMaxIndex(arr, 10);
            double minIndex = findMinIndex(arr, 10);
            double avg = avgIndices(minIndex, maxIndex);



            Assert::AreEqual(6.0, avg, 0.0001); // порівняння з похибкою
        }
	};
}
