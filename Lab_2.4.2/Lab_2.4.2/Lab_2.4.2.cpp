// Lab_02_4.2.cpp
// < Величко Іван >
// Лабораторна робота № 2.4.2
// Масиви та константи в класі
// Варіант 0.4

#include <iostream>
#include "Money.h"
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    // Створення об'єкта Money за допомогою конструктора за замовчуванням
    Money m1;
    cout << "m1 за замовчуванням: " << m1 << endl << m1.toString() << endl << endl;

    // Створення об'єкта Money з параметрами
    Money m2(5, 3);  // Розмір масиву 5, значення елементів 3
    cout << "m2 з параметрами: " << m2 << endl << m2.toString() << endl << endl;

    // Введення даних користувачем для об'єкта Money
    Money m3;
    cin >> m3;  // Введення розміру і значень для масиву
    cout << "m3 після введення: " << m3 << endl << m3.toString() << endl << endl;

    // Перевірка присвоєння (оператор присвоєння '=')
    Money m4 = m3;
    cout << "m4 після присвоєння m3: " << m4 << endl << m4.toString() << endl << endl;

    return 0;
}
