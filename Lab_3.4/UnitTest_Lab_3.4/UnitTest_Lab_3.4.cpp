#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.4/SymString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab34
{
	TEST_CLASS(UnitTestLab34)
	{
	public:

		TEST_METHOD(TestGetValue)
		{
			SymString s("id1", "hello");
			Assert::AreEqual(string("hello"), s.getValue());
		}

		TEST_METHOD(TestGetId)
		{
			SymString s("id2", "world");
			Assert::AreEqual(string("id2"), s.getId());
		}
	};
}
