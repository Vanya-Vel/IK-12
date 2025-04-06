#pragma once
#include "Point.h"

class AccessMethodology : public Point
{
public:
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    // Конструктор за умовчанням
    AccessMethodology() : Point() {}
    // Конструктор з параметрами
    AccessMethodology(int x, int y) : Point(x, y) {}
    // Конструктор копіювання
    AccessMethodology(const AccessMethodology& other) : Point(other) {}
};

