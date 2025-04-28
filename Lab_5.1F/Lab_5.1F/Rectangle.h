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

    int getPerimeter() const {
        return 2 * (sides.getFirst() + sides.getSecond());
    }

    int getArea() const {
        return sides.getFirst() * sides.getSecond();
    }

    void setPair(const Pair& sides) { this->sides = sides; }
    Pair getPair() const { return sides; }
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
    friend std::istream& operator>>(std::istream& in, Rectangle& r);
};
