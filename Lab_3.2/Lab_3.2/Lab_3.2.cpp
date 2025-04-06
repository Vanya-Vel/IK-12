// Lab_03_2.cpp
// < Величко Іван >
// Лабораторна робота № 3.2
// Просте успадкування
// Варіант 0.4
#include <iostream>
#include <windows.h>
#include "SportGame.h"
#include "Football.h"
using namespace std;

int main() {
    // Встановлюємо кодування: 1251 для вводу, 65001 для виводу
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Об'єкти для демонстрації
    SportGame game1("Футбол", 10);
    Football game2("Футбол", 22, "Прем'єр-ліга");

    // Виведення
    cout << "Інформація про спортивну гру:\n";
    game1.display(cout);
    cout << endl;

    cout << "Інформація про футбол:\n";
    game2.display(cout);
    cout << endl;

    // Копіювання
    Football game3 = game2;
    cout << "Копія об'єкта футбол:\n";
    game3.display(cout);
    cout << endl;

    // Введення нового об'єкта SportGame
    SportGame game4;
    cout << "\nВведіть назву гри та кількість гравців: ";
    game4.input(cin);
    cout << "Ви ввели:\n";
    game4.display(cout);
    cout << endl;

    // Введення нового об'єкта Football
    Football game5;
    cout << "\nВведіть назву, кількість гравців та лігу: ";
    game5.input(cin);
    cout << "Ви ввели:\n";
    game5.display(cout);
    cout << endl;

    return 0;
}
