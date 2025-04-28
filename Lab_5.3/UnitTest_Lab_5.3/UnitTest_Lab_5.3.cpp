#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.3/B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab53
{
	TEST_CLASS(UnitTestLab53)
	{
	public:
		
		TEST_METHOD(TestValidCastFromBtoB)
		{
			B b;
			try
			{
				b.copyAndProcess(b); // має пройти без винятку
			}
			catch (...)
			{
				Assert::Fail(L"Не повинно бути винятку при приведенні B до B.");
			}
		
		}
	};
}
