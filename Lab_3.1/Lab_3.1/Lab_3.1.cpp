// Lab_03_1.cpp
// < Величко Іван >
// Лабораторна робота № 3.1
// Відкрите успадкування
// Варіант 0.4

#include "Rectangle.h"
#include "Pair.h"
#include <iostream>
using namespace std;

int main() {
    // === Використання конструктора за замовчуванням ===
    Rectangle rect1;
    cout << "Rectangle 1 (default):" << endl;
    cout << rect1 << endl;

    // === Використання конструктора з параметрами ===
    Pair sides(5, 10);
    Rectangle rect2(sides);
    cout << "\nRectangle 2 (parameterized):" << endl;
    cout << rect2 << endl;

    // === Використання конструктора копіювання ===
    Rectangle rect3(rect2);
    cout << "\nRectangle 3 (copy):" << endl;
    cout << rect3 << endl;

    // === Демонстрація операції присвоєння ===
    Rectangle rect4;
    rect4 = rect2;
    cout << "\nRectangle 4 (=):" << endl;
    cout << rect4 << endl;

    // === Демонстрація операцій інкременту і декременту ===
    cout << "\nRectangle 4:" << endl;
    cout << rect4 << endl;

    // Префіксне інкрементування
    ++rect4;  // Префіксне інкрементування
    cout << "\nRectangle 4 after (++rect4):" << endl;
    cout << rect4 << endl;

    // Постфіксне інкрементування
    rect4++;  // Постфіксне інкрементування
    cout << "\nRectangle 4 after (rect4++):" << endl;
    cout << rect4 << endl;

    // Префіксне декрементування
    --rect4;  // Префіксне декрементування
    cout << "\nRectangle 4 after (--rect4):" << endl;
    cout << rect4 << endl;

    // Постфіксне декрементування
    rect4--;  // Постфіксне декрементування
    cout << "\nRectangle 4 after (rect4--):" << endl;
    cout << rect4;

    // === Виведення площі та периметра прямокутника в буквеному форматі ===
    cout << "\nPerimeter and Area in words:" << endl;
    cout << rect4.toString() << endl;

    Pair sides1;
    Rectangle rect5(sides);
    // === Введення значень для Pair за допомогою оператора вводу ===
    cout << "\nEnter new pair for Rectangle 5:" << endl;
    cin >> sides1;
    cout << "New pair: " << sides1 << endl;


    // Створення прямокутника з оновленим Pair
    rect5.setPair(sides1);
    cout << "\nUpdated Rectangle 5 after pair update: " << endl;
    cout << rect5;

    // === Виведення площі та периметра прямокутника в буквеному форматі ===
    cout << "\nPerimeter and Area in words:" << endl;
    cout << rect5.toString() << endl;

    return 0;
}
