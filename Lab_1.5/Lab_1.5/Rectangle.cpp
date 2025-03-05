#include "Rectangle.h"
#include <iostream>
using namespace std;

void Rectangle::Init(const Pair& sides) {
	setPair(sides);  // Ініціалізація сторін прямокутника через метод setPair
}

void Rectangle::Display() const
{
	cout << endl;
	cout << "Sides of the rectangle: " << endl;
	sides.Display(); // Використовуємо делегування для виведення сторін прямокутника
	cout << "Perimeter: " << getPerimeter() << endl;  // Виведення периметра
	cout << "Area: " << getArea() << endl;  // Виведення площі
}

void Rectangle::Read()
{
	Pair m;
	cout << endl;
	cout << "Enter rectangle sides: " << endl;
	m.Read(); // Використовуємо делегування для введення значень пари
	Init(m);  // Ініціалізація прямокутника отриманими значеннями сторін
}
