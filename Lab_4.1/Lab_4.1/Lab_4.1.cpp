// Lab_04_1.cpp
// < Величко Іван >
// Лабораторна робота № 4.1
// Віртуальні функції та абстрактні класи 
// Варіант 0.4

#include <iostream>
#include "ArithmeticProg.h"
#include "GeometricProg.h"
using namespace std;

int main() {
    const int n = 5; // Кількість елементів у прогресії

    ABase* arr[2]; // Масив вказівників на базовий клас

    double a, dr;

    cout << "first member is: ";
    cin >> a;
    cout << "and the difference (for arithmetic) and the ratio (for geometric progression) is: ";
    cin >> dr;

    // Створення об'єктів арифметичної та геометричної прогресій
    arr[0] = new ArithmeticProg(a, dr);   // a0 = 1, d = 2
    arr[1] = new GeometricProg(a, dr);    // a0 = 1, r = 2

    for (int i = 0; i < 2; i++) {
        std::cout << "Sum of progression " << i + 1 << ": " << arr[i]->sum_progression(n) << std::endl;
    }

    // Звільнення пам’яті
    for (int i = 0; i < 2; ++i) {
        delete arr[i];
    }

    return 0;
}
