#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_6.4/Lab_6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab64
{
	TEST_CLASS(UnitTestLab64)
	{
	public:

		TEST_METHOD(TestSortAscending)
		{
			vector<int> V(5);
			V[0] = 4;
			V[1] = 2;
			V[2] = 5;
			V[3] = 1;
			V[4] = 3;

			V.sort("up");

			Assert::AreEqual(1, V[0]);
			Assert::AreEqual(2, V[1]);
			Assert::AreEqual(3, V[2]);
			Assert::AreEqual(4, V[3]);
			Assert::AreEqual(5, V[4]);
		}
	};
}
