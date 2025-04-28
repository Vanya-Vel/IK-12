#pragma once
#include "ArithmeticOperations.h"
#include <cmath>

class Functions : public ArithmeticOperations
{
public:
    // Метод для переміщення точки по осі X
    void moveX(int stepX) { x += stepX; }

    // Метод для переміщення точки по осі Y
    void moveY(int stepY) { y += stepY; }

    int getX() const { return x; }
    int getY() const { return y; }

    // Метод для обчислення відстані між двома точками
    double distanceFromXtoY(const Functions& other) const;

    // Перетворення об'єкта на строкове подання
    string toString(const Functions& other) const;

    // Перетворення числа на текстове представлення
    string ToNumeral(double number) const;

    // Конструктор за умовчанням
    Functions() : ArithmeticOperations() {}
    // Конструктор з параметрами
    Functions(int y, int x) : ArithmeticOperations(x, y) {}
    // Конструктор копіювання
    Functions(const Functions& other) : ArithmeticOperations(other) {}
};

