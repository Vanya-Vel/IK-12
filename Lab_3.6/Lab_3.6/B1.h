#pragma once
#include <iostream>
using namespace std;

class B1
{
    int b1; // Поле відповідно до імені класу

public:
    // Конструктор ініціалізації
    B1(int x) : b1(x) {}

    // Деструктор
    ~B1() {}

    // Функція для виведення інформації про клас
    void show_B1()
    {
        cout << "class B1:" << endl;
        cout << "B1::b1 = " << b1 << endl << endl;
    }
};
