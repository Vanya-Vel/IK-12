
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
    // Створення об'єкта прямокутника
    Rectangle rect;

    // Введення сторін прямокутника
    rect.Read();

    // Виведення значень: сторони, периметр і площа
    rect.Display();

    return 0;
}
