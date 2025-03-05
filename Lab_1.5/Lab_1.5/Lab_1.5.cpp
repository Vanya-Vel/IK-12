#include "Pair.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
    // Створення об'єкта Pair для зберігання сторін прямокутника
    Pair sides;

    // Введення сторін прямокутника через Pair
    sides.Read(); // Викликається метод Read() для Pair

    // Створення об'єкта Rectangle
    Rectangle rect;

    // Ініціалізація прямокутника через об'єкт Pair
    rect.Init(sides); // Передаємо Pair до Rectangle

    // Виведення сторін, периметру та площі прямокутника
    rect.Display(); // Викликається метод Display() для Rectangle

    return 0;
}
