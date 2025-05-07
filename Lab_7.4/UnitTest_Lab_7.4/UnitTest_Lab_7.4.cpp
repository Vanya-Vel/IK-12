#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.4/Lab_7.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab74
{
	TEST_CLASS(UnitTestLab74)
	{
	public:
		
		TEST_METHOD(FindNonexistentEmployee_ShouldFail)
		{
			map<string, Employee> employees;
			employees["Іванов"] = { "І.П.", "Менеджер", 2010, 12000.0 };

			auto it = employees.find("Петренко");
			Assert::IsTrue(it == employees.end(), L"Службовець не повинен бути знайдений.");
		}
	};
}
