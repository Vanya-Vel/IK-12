#pragma once
#include <string>
#include <istream>
using namespace std;

class Point
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

