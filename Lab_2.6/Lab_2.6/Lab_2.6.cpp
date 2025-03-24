// Lab_02_6.cpp
// < Величко Іван >
// Лабораторна робота № 2.6
// Конструктори та перевантаження операцій для класів з вкладеними класами.Обчислення кількості об’єктів
// Варіант 0.4

#include "Rectangle.h"
#include <iostream>
using namespace std;

int main() {
    // === Використання конструктора за замовчуванням ===
    Rectangle rect1;
    cout << "Rectangle 1 (default):" << endl;
    cout << rect1 << endl;
    cout << "Number of Rectangle objects: " << Rectangle::getCounter() << endl;
    cout << "Number of Pair objects: " << Rectangle::Pair::getCounter() << endl;

    // === Використання конструктора з параметрами ===
    Rectangle::Pair sides(5, 10);
    Rectangle rect2(sides);
    cout << "\nRectangle 2 (parameterized):" << endl;
    cout << rect2 << endl;
    cout << "Number of Rectangle objects: " << Rectangle::getCounter() << endl;
    cout << "Number of Pair objects: " << Rectangle::Pair::getCounter() << endl;

    // === Використання конструктора копіювання ===
    Rectangle rect3(rect2);
    cout << "\nRectangle 3 (copy):" << endl;
    cout << rect3 << endl;
    cout << "Number of Rectangle objects: " << Rectangle::getCounter() << endl;
    cout << "Number of Pair objects: " << Rectangle::Pair::getCounter() << endl;

    // === Демонстрація операції присвоєння ===
    Rectangle rect4;
    rect4 = rect2;
    cout << "\nRectangle 4 (=):" << endl;
    cout << rect4 << endl;
    cout << "Number of Rectangle objects: " << Rectangle::getCounter() << endl;
    cout << "Number of Pair objects: " << Rectangle::Pair::getCounter() << endl;

    // === Демонстрація операцій інкременту і декременту ===
    cout << "\nRectangle 4 before any changes:" << endl;
    cout << rect4 << endl;

    // Префіксне інкрементування
    ++rect4;
    cout << "\nRectangle 4 after (++rect4):" << endl;
    cout << rect4 << endl;

    // Постфіксне інкрементування
    rect4++;
    cout << "\nRectangle 4 after (rect4++):" << endl;
    cout << rect4 << endl;

    // Префіксне декрементування
    --rect4;
    cout << "\nRectangle 4 after (--rect4):" << endl;
    cout << rect4 << endl;

    // Постфіксне декрементування
    rect4--;
    cout << "\nRectangle 4 after (rect4--):" << endl;
    cout << rect4;

    // === Виведення площі та периметра прямокутника в буквеному форматі ===
    cout << "\nPerimeter and Area in words:" << endl;
    cout << rect4.toString() << endl;

    // === Введення значень для Pair ===
    Rectangle::Pair sides1;
    cout << "\nEnter new pair for Rectangle 5:" << endl;
    cin >> sides1;
    cout << "New pair: " << sides1 << endl;

    // Створення прямокутника з оновленим Pair
    Rectangle rect5(sides1);
    cout << "\nUpdated Rectangle 5 after pair update: " << endl;
    cout << rect5;

    // === Виведення площі та периметра в буквеному форматі ===
    cout << "\nPerimeter and Area in words:" << endl;
    cout << rect5.toString() << endl;

    // Виведення кількості об'єктів після всіх операцій
    cout << "\nFinal count:" << endl;
    cout << "Number of Rectangle objects: " << Rectangle::getCounter() << endl;
    cout << "Number of Pair objects: " << Rectangle::Pair::getCounter() << endl;

    return 0;
}
