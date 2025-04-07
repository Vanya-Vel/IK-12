#pragma once
#include "Pair.h"

class Rectangle : public Pair {
protected:
    Pair sides;

public:
    Rectangle();
    Rectangle(const Pair& sides);
    Rectangle(const Rectangle& r);

    Rectangle& operator=(const Rectangle& r);

    // Методи для обчислення периметра та площі
    int getPerimeter() const {
        return 2 * (sides.getFirst() + sides.getSecond());
    }

    int getArea() const {
        return sides.getFirst() * sides.getSecond();
    }

    void setPair(const Pair& sides) { this->sides = sides; } // метод для зміни сторін
    Pair getPair() const { return sides; }
    string toString() const;

    friend ostream& operator<<(ostream& out, const Rectangle& r);
    friend istream& operator>>(istream& in, Rectangle& r);
};
