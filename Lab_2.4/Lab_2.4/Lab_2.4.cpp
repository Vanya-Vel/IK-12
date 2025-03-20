// Lab_02_4.1.cpp
// < Величко Іван >
// Лабораторна робота № 2.4.1
// Перевантаження операцій
// Варіант 0.4

#include <iostream>
#include "Vector.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    // Створення двох векторів
    Vector v1, v2(5, 2), v3(v2);
    Vector v4, v5;

    // Виведення введених векторів
    cout << "v1 за умовчанням: " << v1 << endl;
    cout << "v2 (5,2): " << v2 << endl;
    cout << "v3 копіювання v2: " << v3 << endl;
    cin >> v4;
    cin >> v5;
    cout << "v4: " << v4 << endl;
    cout << "v5: " << v5 << endl;

    // Обчислення скалярного добутку
    Vector v6; 
    v6 = v4 * v5;
    cout << "Скалярний добуток (" << v6.summa() << "): " << v6 << endl;

    // Порівняння векторів
    if (v4.NormVector() == v5.NormVector())
        cout << "Вектори рівні.\n";
    else
        cout << "Вектори не рівні.\n";

    // Обчислення норми векторів
    cout << "Норма v4: " << v4.NormVector() << endl;
    cout << "Норма v5: " << v5.NormVector() << endl;
    cout << "Норма v4: " << v4.toString(v4.NormVector()) << endl;
    cout << "Норма v5: " << v5.toString(v5.NormVector()) << endl << endl;

    Vector v7;
    cout << "Вектор v7 для декременту/інетементу" << endl;
    cin >> v7;

    // декремент/інетемент
    cout << "++v7: " << ++v7 << endl;
    cout << "--v7: " << --v7 << endl;
    cout << "v7++: " << v7++ << endl;
    cout << "v7: " << v7 << endl;
    cout << "v7--: " << v7-- << endl;
    cout << "v7: " << v7 << endl;

    return 0;
}
