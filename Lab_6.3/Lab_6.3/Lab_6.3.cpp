// Lab_06_3.cpp
// < Величко Іван >
// Лабораторна робота № 6.3
// Контейнери-списки
// Варіант 0.4

#include "Rand.h"
#include <iostream>
#include <cmath>
#include "windows.h"
using namespace std;

double myFunction(double x)
{
    return sin(x); // Приклад функції для інтегрування
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const size_t n = 2; // ФІКСОВАНИЙ розмір
    Rand r;  // Об'єкт без параметра, додавання елементів поступове

    cout << "Введіть " << n << " пари (x значення, p ймовірність) для інтегрування (sin(x)) методом Монте-Карло: " << endl;
    for (size_t i = 0; i < n; ++i)
    {
        double x, p;
        cin >> x >> p;
        r.add(x, p);  // Додаємо пару (x, p)
    }

    cout << "\nВаші дані:" << endl;
    r.print();  // Виведення всіх елементів списку

    cout << "\nМатематичне очікування: " << r.mean() << endl;
    cout << "Дисперсія: " << r.variance() << endl;

    double a, b;
    size_t N;
    cout << "\nВведіть межі інтегрування a і b: ";
    cin >> a >> b;
    cout << "Введіть кількість випадкових точок N: ";
    cin >> N;

    double integral = r.monteCarloIntegral(myFunction, a, b, N);
    cout << "Інтеграл методом Монте-Карло: " << integral << endl;

    return 0;
}
