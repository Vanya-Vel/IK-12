// Lab_01_2.cpp
// < Величко Іван >
// Лабораторна робота № 1.2
// Оголошення та будова класу
// Варіант 0.4

#define _USE_MATH_DEFINES // Підключаємо макрос, який дозволяє використовувати M_PI для значення числа Пі
#include <iostream>
#include "Circle.h" // Підключаємо заголовочний файл класу Circle

using namespace std;

int main()
{
    Circle g; // Створюємо об'єкт класу Circle

    g.Read(); // Викликаємо метод Read(), щоб користувач міг ввести координати та радіус кола

    g.Display(); // Викликаємо метод Display() для виведення інформації про центр кола та його радіус

    // Обчислюємо та виводимо площу кола за допомогою методу AreaOfCircle()
    cout << "Area of a circle: " << g.AreaOfCircle() << endl;

    // Обчислюємо та виводимо довжину кола за допомогою методу CircleLength()
    cout << "Length of a circle: " << g.CircleLength() << endl;

    return 0;
}
