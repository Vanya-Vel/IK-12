#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

class Rectangle {
private:
    Pair sides;

public:
    Rectangle();  // Конструктор без аргументів
    Rectangle(const Pair& sides);  // Конструктор з параметрами
    Rectangle(const Rectangle& r);  // Конструктор копіювання

    // Методи доступу
    Pair getPair() const;
    void setPair(const Pair& sides);

    // Обчислення периметра
    int getPerimeter() const;

    // Обчислення площі
    int getArea() const;

    // Операція присвоєння
    Rectangle& operator=(const Rectangle& r);

    // Операції інкременту і декременту
    Rectangle& operator++();  // Префікс
    Rectangle operator++(int);  // Постфікс
    Rectangle& operator--();  // Префікс
    Rectangle operator--(int);  // Постфікс

    // Виведення значень
    friend ostream& operator<<(ostream& out, const Rectangle& r);

    // Введення значень
    friend istream& operator>>(istream& in, Rectangle& r);

    // Перетворення в буквеному форматі
    string toString() const;
};
