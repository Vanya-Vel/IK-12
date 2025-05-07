#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.5/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab65
{
	TEST_CLASS(UnitTestLab65)
	{
	public:
		
		TEST_METHOD(TestMethod_StackInt)
		{
			Stack<int> s_int(2);
			s_int.push(10);
			s_int.push(20);

			Assert::AreEqual(20, s_int.top());
		}
	};
}
