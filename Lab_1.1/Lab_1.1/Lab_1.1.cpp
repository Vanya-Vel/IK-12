// Lab_01_1.cpp
// < Величко Іван >
// Лабораторна робота № 1.1
// Поля та методи – дії над одним(поточним) об’єктом
// Варіант 0.4

#include <iostream> 
#include "Money.h"

using namespace std;

// Функція для створення об'єкта Money з перевіркою коректності введених значень
Money makeNumber2(int x, int y)
{
    Money nn;
    if (!nn.Init(x, y)) // Викликаємо Init для ініціалізації об'єкта
    {
        cout << "wrong argument to Init" << endl; // Повідомлення про неправильні дані
    }
    return nn; // Повертаємо створений об'єкт (навіть якщо ініціалізація невдала)
}

int main()
{
    Money k;
    k.Read(); // Зчитуємо значення від користувача
    k.Display(); // Виводимо поточні значення об'єкта
    cout << "Summa " << k.Summa() << endl << endl;

    Money i;
    int den, num;
    cout << "first = ? ";
    cin >> den; // Введення номіналу
    cout << "second = ? ";
    cin >> num; // Введення кількості номіналів
    i = makeNumber2(den, num); // Створюємо об'єкт через функцію makeNumber2()
    i.Display(); // Виводимо значення об'єкта
    cout << "Summa " << i.Summa() << endl << endl;
    return 0;
}
