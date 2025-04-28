#pragma once
#include <string>
#include <istream>
#include <stdexcept>
#include <cmath>
#include <iostream>
using namespace std;

// Визначення власного винятку
class PointException : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка в операціях з точкою!";
    }
};

class Point
{
private:
    int x, y;

public:
    Point();                    // Конструктор за умовчанням
    Point(int, int);            // Конструктор з двома параметрами (ініціалізація)
    Point(const Point&);        // Конструктор копіювання

    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    // Метод для переміщення точки по осі X
    void moveX(int stepX) { x += stepX; }

    // Метод для переміщення точки по осі Y
    void moveY(int stepY) { y += stepY; }

    // Метод для обчислення відстані між двома точками
    double distanceFromXtoY(const Point& other) const;

    // Перетворення об'єкта на строкове подання
    string toString(const Point& other) const;

    // Перетворення числа на текстове представлення
    string ToNumeral(double number) const;

    Point operator + (const Point&);        // Операція додавання точок
    Point& operator = (const Point&);       // Операція присвоєння

    Point& operator ++();     // Префіксний інкремент
    Point& operator --();     // Префіксний декремент
    Point operator ++(int);   // Постфіксний інкремент
    Point operator --(int);   // Постфіксний декремент

    // Друк точки у потік
    friend ostream& operator << (ostream&, const Point&);

    // Введення точки з потоку
    friend istream& operator >> (istream&, Point&);
};
