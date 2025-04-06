#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.2/SportGame.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab32
{
	TEST_CLASS(UnitTestLab32)
	{
	public:
		
		TEST_METHOD(Test_Copy)
		{
			SportGame game1("Футбол", 10);
			SportGame game3(game1);

			Assert::IsTrue(game3 == game1);
		}
	};
}
