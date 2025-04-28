#include <iostream>
#include <stdexcept>
#include "windows.h"
#include "A.h"
#include "B.h"

int main() {
    SetConsoleOutputCP(1251);
    try {
        std::cout << "Створення об'єкта класу A..." << std::endl;
        A a;  // Створюємо об'єкт класу A
        std::cout << "Створення об'єкта класу B..." << std::endl;
        B b;  // Створюємо об'єкт класу B

        std::cout << "\nСпроба привести A до B (не повинно вийти):" << std::endl;
        b.copyAndProcess(a);  // Спроба привести A до B (не повинно вийти)

        std::cout << "\nСпроба привести B до B (повинно вийти):" << std::endl;
        b.copyAndProcess(b);  // Тут не повинно бути винятку
    }
    catch (const std::exception& e) {
        std::cout << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}