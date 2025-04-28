#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.2/Lab_5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab52
{
	TEST_CLASS(UnitTestLab52)
	{
	public:
		
        // Тест для функції convertToSeconds1, яка кидає "Invalid time"
        TEST_METHOD(TestConvertToSeconds1_InvalidTime)
        {
            try {
                // Викликаємо функцію з неправильними параметрами
                int seconds = convertToSeconds1(-1, 60); // Невірний час
                Assert::Fail(L"Expected exception was not thrown.");
            }
            catch (const char* msg) {
                Assert::AreEqual("Invalid time", msg); // Перевіряємо, що виняток має правильне повідомлення
            }
        }

        // Тест для функції convertToSeconds3, яка кидає std::invalid_argument
        TEST_METHOD(TestConvertToSeconds3_InvalidTime)
        {
            try {
                // Викликаємо функцію з неправильними параметрами
                int seconds = convertToSeconds3(25, 60); // Невірний час
                Assert::Fail(L"Expected exception was not thrown.");
            }
            catch (const std::invalid_argument& e) {
                Assert::AreEqual("Invalid time", std::string(e.what()).c_str()); // Перевіряємо правильність повідомлення винятку
            }
        }

	};
}
