// Lab_05_1G.cpp
// < Величко Іван >
// Лабораторна робота № 5.1G
// Класи з опрацюванням виняткових ситуацій
// Варіант 0.4

#include <iostream>
#include "pFunctions.h"  // Для pFunctions
#include "Rectangle.h"   // Для Rectangle
#include "Pair.h"        // Для Pair
#include <stdexcept>     // Для стандартних винятків

using namespace std;

int main() {
    // Створення об'єкта класу Pair
    Pair p, p1(5, 3);
    cout << "Pair p default: " << p << endl;
    cout << "Pair p1 parametrized: " << p1 << endl;
    cout << "Count object = " << Object::Count() << endl << endl;

    int a, b;
    cout << "Write a and b: ";
    cin >> a >> b;

    try {
        if (a <= 0 || b <= 0) {
            // Генерація власного винятку
            // Генерація винятку для некоректного вибору
            try {
                throw PointException();
            }
            catch (PointException e) {
                cout << "[by value] Exception: " << e.what() << endl;              // Виняток за значенням
            }

            try {
                throw PointException();
            }
            catch (PointException& e) {
                cout << "[by reference] Exception: " << e.what() << endl;          // Виняток за посиланням
            }

            try {
                throw new PointException();
            }
            catch (PointException* e) {
                cout << "[by pointer] Exception: " << e->what() << endl << endl;   // Виняток за вказівником
                delete e;
            }
            throw PointException();
        }
        Pair p2(a, b);
        Rectangle rect1(p2);
        cout << "Rectangle rect1: " << rect1;
        cout << "toString: " << rect1.toString() << endl << endl;
    }

    catch (const PointException& ex) {}

    // Створення об'єкта класу pFunctions для виконання арифметичних операцій
    pFunctions pFunc(7, 4);
    cout << "Initial pFunctions (7, 4) toString : " << pFunc.toString() << endl;

    // Операції інкременту та декременту
    try {
        ++pFunc;  // Префіксний інкремент
        cout << "After prefix increment: " << pFunc.toString() << endl;

        pFunc++;  // Постфіксний інкремент
        cout << "After postfix increment: " << pFunc.toString() << endl;

        --pFunc;  // Префіксний декремент
        cout << "After prefix decrement: " << pFunc.toString() << endl;

        pFunc--;  // Постфіксний декремент
        cout << "After postfix decrement: " << pFunc.toString() << endl << endl;
    }
    catch (const std::exception& e) {
        cout << "Caught exception (standard by reference): " << e.what() << endl;
    }

    cout << "Count object = " << Object::Count() << endl << endl;

    return 0;
}
