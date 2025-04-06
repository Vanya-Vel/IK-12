#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() : Pair() {}

Rectangle::Rectangle(const Pair& sides) : Pair(sides) {}

Rectangle::Rectangle(const Rectangle& r) : Pair(r) {}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        setFirst(r.getFirst());
        setSecond(r.getSecond());
    }
    return *this;
}

Rectangle& Rectangle::operator++() {
    Pair::operator++();
    return *this;
}

Rectangle Rectangle::operator++(int) {
    Rectangle temp = *this;
    Pair::operator++();
    return temp;
}

Rectangle& Rectangle::operator--() {
    Pair::operator--();
    return *this;
}

Rectangle Rectangle::operator--(int) {
    Rectangle temp = *this;
    Pair::operator--();
    return temp;
}

ostream& operator<<(ostream& out, const Rectangle& r) {
    out << "Rectangle sides: " << r.toString() << endl;
    out << "Perimeter: " << r.getPerimeter() << endl;
    out << "Area: " << r.getArea() << endl;
    return out;
}

istream& operator>>(istream& in, Rectangle& r) {
    int first, second;
    cout << "Enter first side: ";
    in >> first;
    cout << "Enter second side: ";
    in >> second;
    r.setFirst(first);
    r.setSecond(second);
    return in;
}

string Rectangle::toString() const {
    return "First = " + to_string(getFirst()) + ", Second = " + to_string(getSecond());
}
