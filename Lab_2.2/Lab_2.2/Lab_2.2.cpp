﻿// Lab_02_2.cpp
// < Величко Іван >
// Лабораторна робота № 2.2
// Перевантаження операцій
// Варіант 0.4

#include <iostream>
#include "Matrix.h"
#include <windows.h>

int main()
{
    // Встановлення кодування для кирилиці у Windows
    SetConsoleOutputCP(1251);

	Matrix m1;        // конструктор за умовчанням
	Matrix m2(0);		// конструктор з одним параметром
	Matrix m3(2, 5);	// конструктор з двома параметрами
    Matrix m4;	        
    Matrix m5;	        
	Matrix m6(m4);      // конструктор копіювання

    cout << "За умовчанням m1:  " << m1 << endl;
    cout << "Один параметр m2:  " << m2 << endl;
    cout << "Два параметри m3:  " << m3 << endl;
    cout << "Копіювання m6:  " << m6 << endl;

    // Введення елементів матриць
    cout << "Введіть матрицю m4 для + - += -=:\n";
    cin >> m4;
    cout << "Введіть матрицю m5 для + - += -=:\n";
    cin >> m5;

    // Виведення матриць
    cout << "m4:  " << m4 << endl;
    cout << "m5:  " << m5 << endl;

    cout << "+:  " << m4 + m5 << endl;
    cout << "-:  " << m4 - m5 << endl;

    Matrix m7 = (m4 - m5);
    cout << "=: (присвоєння попереднього результату m7)  " << m7 << endl;

    m7 += m5;
    cout << "+=: (m7 += m5) " << m7 << endl;

    m7 -= m5;
    cout << "-=: (m7 -= m5) " << m7 << endl;


    Matrix m8;
    Matrix m9;
    // Введення елементів матриць
    cout << "Введіть матрицю m8 для *:\n";
    cin >> m8;
    cout << "Введіть матрицю m9 для *:\n";
    cin >> m9;

    // Виведення матриць
    cout << "Перша матриця:  " << m8 << endl;
    cout << "Друга матриця:  " << m9 << endl;

    cout << "*:  " << m8 * m9 << endl;
    m8 *= m8 * m9;
    cout << "*= (m8 * попередній результат):  " << m8 << endl;

    return 0;
}
