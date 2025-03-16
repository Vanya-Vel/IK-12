// Lab_02_1.cpp
// < Величко Іван >
// Лабораторна робота № 2.1
// Конструктори та перевантаження операцій для класів з двома полями
// Варіант 0.4

#include <iostream> 
#include "Money.h"
#include <windows.h>
#include <sstream>

using namespace std;

// Функція для створення об'єкта Money з перевіркою коректності введених значень
Money makeMoney(int x, int y)
{
    int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };

    // Перевірка на правильний номінал
    for (int denom : validDenoms) {
        if (x == denom && y > 0) {
            return Money(x, y);  // Якщо номінал правильний і кількість більше 0, повертаємо об'єкт Money
        }
    }

    // Якщо помилка: або неправильний номінал, або кількість купюр менша або рівна 0
    cout << "Неправильний номінал або кількість купюр має бути більшою за 0!" << endl;
    return Money();  // Повертаємо об'єкт з 0-значеннями
}

int main() {
    // Встановлення кодування для кирилиці у Windows
    SetConsoleOutputCP(1251);

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

            Money money = makeMoney(denom, count);  // Виклик функції для створення об'єкта Money

            if (money.GetFirst() != 0 && money.GetSecond() != 0) {  // Перевірка на коректність
                cout << "Об'єкт Money створено: " << money << endl;
                break;  // Вихід з циклу при успішному створенні
            }
        }
    }

    return 0;
}
