#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846 // Перевизначення значення числа Пі, якщо воно не визначене
#endif
#include <string>

using namespace std;

class Circle
{
private:
    int x, y; // Координати центру кола
    double radius; // Радіус кола
public:
    int getX() const { return x; } // Геттер для x-координати
    int getY() const { return y; } // Геттер для y-координати
    double getRadius() const { return radius; } // Геттер для радіусу кола
    void setX(int value) { x = value; } // Сеттер для x-координати
    void setY(int value) { y = value; } // Сеттер для y-координати
    void setRadius(double value) { radius = value; } // Сеттер для радіусу кола

    bool Init(int x, int y, double radius); // Метод для ініціалізації координат і радіусу кола
    double AreaOfCircle() const { return M_PI * radius * radius; } // Метод для обчислення площі кола
    double CircleLength() const { return 2 * M_PI * radius; } // Метод для обчислення довжини кола

    void Display() const; // Метод для виведення інформації про коло
    void Read(); // Метод для зчитування параметрів кола від користувача
};
