#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1.2/Lab_7.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab712
{
	TEST_CLASS(UnitTestLab712)
	{
	public:
		
        TEST_METHOD(TestMethod)
        {
            vector<int> v = { 5, -3, 17, 8, -10, 25, 0, -99, 13, 25 };

            double maxIndex = findMaxIndex(v);
            double minIndex = findMinIndex(v);
            double avg = avgIndices(minIndex, maxIndex);



            Assert::AreEqual(6.0, avg, 0.0001); // порівняння з похибкою
        }


	};
}
