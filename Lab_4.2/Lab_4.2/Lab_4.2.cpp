// Lab_04_2.cpp
// < Величко Іван >
// Лабораторна робота № 4.2
// Інтерфейси (до 4.1)
// Варіант 0.4

#include <iostream>
#include <typeinfo>
#include "ArithmeticProg.h"
#include "GeometricProg.h"
#include "ABase.h"
using namespace std;

int main() {
    const int n = 5;

    // Масив поліморфних об'єктів
    ABase* arr[2];

    arr[0] = new ArithmeticProg(1.0, 2.0);  // a0=1, d=2
    arr[1] = new GeometricProg(1.0, 2.0);   // a0=1, r=2

    for (int i = 0; i < 2; ++i) {
        cout << "Object type: " << typeid(*arr[i]).name() << endl;
        cout << "Sum of progression: " << arr[i]->sum_progression(n) << endl;
        cout << endl;
    }

    // Очищення пам’яті
    for (int i = 0; i < 2; ++i)
        delete arr[i];

    return 0;
}
