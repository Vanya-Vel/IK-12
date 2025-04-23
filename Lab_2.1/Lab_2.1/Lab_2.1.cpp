// Lab_02_1.cpp
// < Величко Іван >
// Лабораторна робота № 2.1
// Конструктори та перевантаження операцій для класів з двома полями
// Варіант 0.4

#include <iostream> 
#include "Money.h"
#include <windows.h>
#include <sstream>
#include <stdexcept>

using namespace std;

// Стандартний виняток
void testStandardException(int x) throw(std::invalid_argument) {
    if (x < 0) {
        throw std::invalid_argument("Значення не може бути від'ємним!");
    }
    cout << "Значення коректне: " << x << endl;
}

// Виняток-нащадок від стандартного
class CustomInvalidArgument : public std::invalid_argument {
public:
    explicit CustomInvalidArgument(const std::string& message)
        : std::invalid_argument(message) {}
};

void testCustomException(int x) throw(CustomInvalidArgument) {
    if (x < 0) {
        throw CustomInvalidArgument("Негативне значення!");
    }
    cout << "Значення коректне: " << x << endl;
}

// Власний виняток
class MyException {
public:
    std::string message;
    explicit MyException(const std::string& msg) : message(msg) {}
};

void testMyException(int x) throw(MyException) {
    if (x < 0) {
        throw MyException("Негативне значення!");
    }
    cout << "Значення коректне: " << x << endl;
}

// Обробка винятку std::bad_exception
void testBadException() throw() {
    throw std::bad_exception();
}

// Функція для створення об'єкта Money з перевіркою коректності введених значень
Money makeMoney(int x, int y) throw(std::invalid_argument) {
    int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };

    // Перевірка на правильний номінал
    bool isValid = false;
    for (int denom : validDenoms) {
        if (x == denom && y > 0) {
            isValid = true;
            break;
        }
    }

    if (!isValid) {
        throw std::invalid_argument("Неправильний номінал або кількість купюр має бути більшою за 0!");
    }

    return Money(x, y);
}

int main() {
    // Встановлення кодування для кирилиці у Windows
    SetConsoleOutputCP(1251);

    // Тестування стандартного винятку
    try {
        testStandardException(-1);
    }
    catch (const std::invalid_argument& e) {
        cout << "Обробка стандартного винятку: " << e.what() << endl;
    }

    // Тестування винятку-нащадка
    try {
        testCustomException(-5);
    }
    catch (const CustomInvalidArgument& e) {
        cout << "Обробка винятку-нащадка: " << e.what() << endl;
    }

    // Тестування власного винятку
    try {
        testMyException(-10);
    }
    catch (const MyException& e) {
        cout << "Обробка власного винятку: " << e.message << endl;
    }

    // Тестування стандартного винятку bad_exception
    try {
        testBadException();
    }
    catch (const std::bad_exception& e) {
        cout << "Обробка винятку bad_exception: " << e.what() << endl;
    }

    // Тестування конструктора за замовчуванням
    Money money1;
    cout << "Money1 (Конструктор за замовчуванням):" << endl << money1;

    // Тестування параметризованого конструктора
    Money money2(100, 5); // номінал 100, кількість купюр 5
    cout << "Money2 (Параметризований конструктор):" << endl << money2;

    // Тестування введення через оператор >>
    Money money3;
    cout << "Введіть дані для Money3:" << endl;
    cin >> money3;  // Введення даних для об'єкта money3
    cout << "Money3 (Після введення):" << endl << money3 << endl << endl;

    // Тестування префіксних та постфіксних інкрементів і декрементів
    cout << "Інкрементуємо та декрементуємо money3: " << endl << money3 << endl;
    cout << "Преінкремент: " << endl << ++money3 << endl;
    cout << "Постінкремент: " << endl << money3++ << endl;
    cout << "Money3: " << endl << money3 << endl;
    cout << "Предекремент:" << endl << --money3 << endl;
    cout << "Постдекремент:" << endl << money3-- << endl;
    cout << "Money3:" << endl << money3 << endl;

    // Тестування оператора множення
    Money result = money2 * 3;
    cout << "Результат (Money2 * 3):" << endl << result << endl;

    // Тестування оператора присвоєння
    Money money4 = money3;  // Присвоєння об'єкта money3 об'єкту money4
    cout << "Money4 (Після присвоєння від Money1):" << endl << money4 << endl;

    // Перевірка коректності введених даних через зовнішню функцію
    int p;
    cout << "Перевірити коректність значень зовнішньою функцією? (1 - yes; 0 no) ";
    cin >> p;
    if (p == 1)
    {
        int denom, count;
        // Цикл для перевірки правильності введених даних
        while (true) {
            cout << "Номінал (1, 2, 5, 10, 20, 50, 100, 200, 500): ";
            cin >> denom;
            cout << "Кількість купюр: ";
            cin >> count;

            try {
                Money money = makeMoney(denom, count);  // Виклик функції для створення об'єкта Money
                cout << "Об'єкт Money створено: " << money << endl;
                break;  // Вихід з циклу при успішному створенні
            }
            catch (const std::invalid_argument& e) {
                cout << "Помилка: " << e.what() << endl;
            }
        }
    }

    return 0;
}
