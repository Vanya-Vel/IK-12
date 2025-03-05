#include "Rectangle.h"
#include <iostream>
using namespace std;

// Ініціалізація прямокутника, встановлюється пара сторін
void Rectangle::Init(Rectangle::Pair sides) {
    setPair(sides);  // Викликаємо метод для встановлення пари сторін
}

// Виведення інформації про прямокутник: сторони, периметр і площа
void Rectangle::Display() const
{
    cout << endl;
    cout << "Sides of the rectangle: " << endl;
    sides.Display();  // Використовуємо делегування: виводимо сторони через метод Pair
    cout << "Perimeter: " << getPerimeter() << endl;  // Виведення периметра прямокутника
    cout << "Area: " << getArea() << endl;  // Виведення площі прямокутника
}

// Зчитування сторін прямокутника від користувача
void Rectangle::Read()
{
    Rectangle::Pair m;
    cout << endl;
    cout << "Enter rectangle sides: " << endl;
    m.Read();  // Використовуємо делегування для введення сторін
    Init(m);  // Ініціалізуємо прямокутник введеними сторонами
}

// Ініціалізація пари сторін прямокутника
void Rectangle::Pair::Init(int first, int second)
{
    setFirst(first);  // Встановлюємо першу сторону
    setSecond(second);  // Встановлюємо другу сторону
}

// Виведення сторін пари
void Rectangle::Pair::Display() const
{
    cout << endl;
    cout << "First number = " << first << endl;
    cout << "Second number = " << second << endl;
}

// Зчитування сторін пари від користувача
void Rectangle::Pair::Read()
{
    int first, second;
    cout << endl;
    cout << "First = ? "; cin >> first;
    cout << "Second = ? "; cin >> second;
    Init(first, second);  // Ініціалізація пари введеними значеннями
}
