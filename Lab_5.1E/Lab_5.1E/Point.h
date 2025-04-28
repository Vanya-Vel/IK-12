#pragma once
#include "Object.h" 
#include <string>
#include <istream>
using namespace std;

// Визначення власного винятку
class PointException : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка в операціях з точкою!";
    }
};

class Point : public Object
{
protected:
    int x, y;

public:
    Point();                    // Конструктор за умовчанням
    Point(int, int);            // Конструктор з двома параметрами (ініціалізація)
    Point(const Point&);        // Конструктор копіювання

    bool operator > (const Point&) const;

    // Введення/виведення
    friend ostream& operator << (ostream&, const Point&);
    friend istream& operator >> (istream&, Point&);
};

