#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3.6/D3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab36
{
	TEST_CLASS(UnitTestLab36)
	{
	public:
		
        TEST_METHOD(TestMethodB1_Show)
        {
            // Створюємо об'єкт класу B1 і передаємо значення 777 для ініціалізації
            B1 b1(777);

            // Перенаправляємо стандартний потік виведення (std::cout) в строковий потік
            std::stringstream output;
            std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(output.rdbuf()); // Зберігаємо старий буфер для виведення

            // Викликаємо функцію show_B1, яка виведе інформацію на стандартний потік
            b1.show_B1();

            // Відновлюємо стандартний потік виведення після завершення тесту
            std::cout.rdbuf(oldCoutStreamBuf); // Повертаємо потік виведення назад

            // Перевіряємо, чи виведено правильне значення в output
            // Шукаємо підрядок "B1::b1 = 777" в строковому потоці
            Assert::IsTrue(output.str().find("B1::b1 = 777") != std::string::npos);
        }
        ''
	};
}
