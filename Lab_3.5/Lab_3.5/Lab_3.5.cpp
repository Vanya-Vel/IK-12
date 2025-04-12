// Lab_03_5.cpp
// < Величко Іван >
// Лабораторна робота № 3.5
// Масиви та успадкування
// Варіант 0.4


#include "Decimal.h"
#include <iostream>
#include "windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // 1. Створення об’єктів різними способами
    Decimal a("12345");                      // конструктор з рядка
    Decimal b("987");                        // ще один об’єкт
    Decimal c;                               // конструктор за замовчуванням
    Decimal d = a;                           // копіювання
    Decimal e; e = b;                        // присвоєння

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "c = " << c << " (default)\n";
    std::cout << "d = " << d << " (копія a)\n";
    std::cout << "e = " << e << " (присвоєння b)\n\n";

    // 2. Арифметичні операції
    Decimal sum = a + b;
    Decimal diff = a - b;
    Decimal prod = a * b;

    std::cout << "Сума (a + b): " << sum << "\n";
    std::cout << "Різниця (a - b): " << diff << "\n";
    std::cout << "Добуток (a * b): " << prod << "\n\n";

    // 3. Операції порівняння
    std::cout << "a == b? " << (a == b ? "так" : "ні") << "\n";
    std::cout << "a != b? " << (a != b ? "так" : "ні") << "\n";
    std::cout << "a < b?  " << (a < b ? "так" : "ні") << "\n";
    std::cout << "a <= b? " << (a <= b ? "так" : "ні") << "\n";
    std::cout << "a > b?  " << (a > b ? "так" : "ні") << "\n";
    std::cout << "a >= b? " << (a >= b ? "так" : "ні") << "\n\n";

    // 4. Перевірка методів базового класу
    std::cout << "Розмір a: " << a.getSize() << "\n";
    std::cout << "Цифра в a[0] (одиниці): " << static_cast<int>(a[0]) << "\n";

    // Невірний індекс: rangeCheck (викликає завершення програми)
    if (c.rangeCheck(150)) {
        std::cout << "a[150] = " << static_cast<int>(a[150]) << "\n";
    }
    else {
        std::cout << "Помилка: індекс 150 виходить за межі.\n";
    }

    // 5. Зміна розміру масиву
    Decimal testResize("50");
    testResize.setSize(3);
    std::cout << "Змінений розмір (має бути 3): " << testResize.getSize() << "\n";

    // 6. Метод toString()
    std::string str = a.toString();
    std::cout << "Число a у вигляді рядка: " << str << "\n\n";

    // 7. Ввід з клавіатури
    Decimal input1, input2;
    std::cout << "Введіть два десяткові числа:\n";
    std::cin >> input1 >> input2;
    std::cout << "input1 = " << input1 << ", input2 = " << input2 << "\n";

    // 8. Масив об’єктів Decimal
    Decimal arr[3] = { Decimal("11"), Decimal("22"), Decimal("33") };
    std::cout << "Масив об'єктів Decimal:\n";
    for (int i = 0; i < 3; ++i)
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";

    return 0;
}
