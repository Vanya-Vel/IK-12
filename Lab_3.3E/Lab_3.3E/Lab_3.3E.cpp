// Lab_03_3E.cpp
// < Величко Іван >
// Лабораторна робота № 3.3E
// Успадкування замість композиції
// Варіант 0.4

#include <iostream>
#include "pFunctions.h"  // Для pFunctions
#include "Rectangle.h"   // Для Rectangle
#include "Pair.h"        // Для Pair

using namespace std;

int main() {
    // Створення об'єкта класу Pair
    Pair p, p1(5, 3);
    cout << "Pair p default: " << p << endl;
    cout << "Pair p1 parametrized: " << p1 << endl << endl;

    int a, b;
    cout << "write a and b: ";
    cin >> a >> b;
    Pair p2(a, b);

    // Створення об'єкта класу Rectangle за допомогою Pair
    Rectangle rect1(p2);
    cout << "Rectangle rect1: " << rect1;
    cout << "toString: " << rect1.toString() << endl;
    cout << "Count object = " << Object::Count() << endl << endl;

    // Створення об'єкта класу pFunctions для виконання арифметичних операцій
    pFunctions pFunc(7, 4);
    cout << "Initial pFunctions (7, 4) toString: " << pFunc.toString() << endl;

    // Операції інкременту та декременту
    ++pFunc;  // Префіксний інкремент
    cout << "After prefix increment: " << pFunc.toString() << endl;

    pFunc++;  // Постфіксний інкремент
    cout << "After postfix increment: " << pFunc.toString() << endl;

    --pFunc;  // Префіксний декремент
    cout << "After prefix decrement: " << pFunc.toString() << endl;

    pFunc--;  // Постфіксний декремент
    cout << "After postfix decrement: " << pFunc.toString() << endl << endl;

    Rectangle p3;
    p3 = pFunc;
    cout << "p3 = pFunc(7, 4): " << p3;
    cout << "toString: " << p3.toString() << endl;
    cout << "Count object = " << Object::Count() << endl << endl;

    return 0;
}
