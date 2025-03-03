#include "Circle.h"
#include <iostream>

using namespace std;

void Circle::setX(int value)
{
    x = value; // Сеттер для координати x: присвоює значення параметра value змінній x
}

void Circle::setY(int value)
{
    y = value; // Сеттер для координати y: присвоює значення параметра value змінній y
}

void Circle::setRadius(double value)
{
    radius = value; // Сеттер для радіусу кола: присвоює значення параметра value змінній radius
}

bool Circle::Init(int x, int y, double radius)
{
    if (radius > 0) // Перевіряємо, чи радіус більше за нуль
    {
        this->x = x;  // Якщо так, ініціалізуємо координати і радіус
        this->y = y;
        this->radius = radius;
        return true; // Повертаємо true, якщо ініціалізація успішна
    }
    else
    {
        this->x = x; // Якщо радіус некоректний (менший або рівний нулю), ініціалізуємо координати, але ставимо радіус рівним 0
        this->y = y;
        this->radius = 0;  // Мінімально допустиме значення радіусу
        return false; // Повертаємо false, якщо ініціалізація не вдалася
    }
}

void Circle::Display() const
{
    cout << " centre coordinates = (" << x << "; " << y << ")" << endl; // Виведення координат центру кола
    cout << " radius = " << radius << endl; // Виведення радіусу кола
}

void Circle::Read()
{
    int x, y;
    double radius;
    do {
        cout << " Coordinate x = ? "; cin >> x; // Зчитуємо x-координату
        cout << " coordinate y = ? "; cin >> y; // Зчитуємо y-координату
        cout << " Radius = ? "; cin >> radius; // Зчитуємо радіус
    } while (!Init(x, y, radius)); // Якщо ініціалізація не вдалася (радіус <= 0), запитуємо введення знову
}
