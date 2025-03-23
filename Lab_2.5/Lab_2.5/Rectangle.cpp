#include "Rectangle.h"
#include "Pair.h"
#include <iostream>
#include <cmath>
using namespace std;

Rectangle::Rectangle() {}

Rectangle::Rectangle(const Pair& sides) : sides(sides) {}

Rectangle::Rectangle(const Rectangle& r) : sides(r.sides) {}

Pair Rectangle::getPair() const { return sides; }

void Rectangle::setPair(const Pair& sides) { this->sides = sides; }

int Rectangle::getPerimeter() const {
    return 2 * (sides.getFirst() + sides.getSecond());
}

int Rectangle::getArea() const { return sides.multiply(); }

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        sides = r.sides;
    }
    return *this;
}

Rectangle& Rectangle::operator++() {
    ++sides;
    return *this;
}

Rectangle Rectangle::operator++(int) {
    Rectangle temp = *this;
    ++sides;
    return temp;
}

Rectangle& Rectangle::operator--() {
    --sides;
    return *this;
}

Rectangle Rectangle::operator--(int) {
    Rectangle temp = *this;
    --sides;
    return temp;
}

ostream& operator<<(ostream& out, const Rectangle& r) {
    out << "Rectangle sides: " << r.sides.toString() << endl;
    out << "Perimeter: " << r.getPerimeter() << endl;
    out << "Area: " << r.getArea() << endl;
    return out;
}

istream& operator>>(istream& in, Rectangle& r) {
    Pair p;
    in >> p;
    r.setPair(p);
    return in;
}

string Rectangle::toString() const {
    int perimeter = getPerimeter();
    int area = getArea();

    const string ones[] = { "nul", "odyn", "dva", "try", "chotyry", "p’yat", "shist", "sim", "vysim", "dev'yat" };
    const string teens[] = { "desyat", "odynadtsyat", "dvanadtsyat", "trynadtsyat", "chotyrnadtsyat", "p'yatnadtsyat", "shistnadtsyat", "simnadtsyat", "vysimnadtsyat", "dev'yatnadtsyat" };
    const string tens[] = { "", "desyat", "dvadsyt", "trydtsyat", "sorok", "p'yatdesyat", "shistdesyat", "simdesyat", "vysymdesyat", "devyanosto" };
    const string hundreds[] = { "", "sto", "dvisti", "trysta", "chotyrysta", "p'yatsot", "shist'sot", "sim'sot", "vysim'sot", "dev'yatsot" };

    string result = "Perimeter: ";
    int perimeterPart = perimeter;

    // Визначення сотень, десятків та одиниць для периметра
    int perimeterHundreds = perimeterPart / 100;
    int perimeterTens = (perimeterPart % 100) / 10;
    int perimeterOnes = perimeterPart % 10;

    if (perimeterHundreds > 0) result += hundreds[perimeterHundreds] + " ";
    if (perimeterTens == 1) result += teens[perimeterOnes] + " ";
    else {
        if (perimeterTens > 1) result += tens[perimeterTens] + " ";
        if (perimeterOnes > 0) result += ones[perimeterOnes] + " ";
    }

    result += "meters. ";

    // Тепер робимо те саме для площі
    result += "Area: ";
    int areaPart = area;
    int areaHundreds = areaPart / 100;
    int areaTens = (areaPart % 100) / 10;
    int areaOnes = areaPart % 10;

    if (areaHundreds > 0) result += hundreds[areaHundreds] + " ";
    if (areaTens == 1) result += teens[areaOnes] + " ";
    else {
        if (areaTens > 1) result += tens[areaTens] + " ";
        if (areaOnes > 0) result += ones[areaOnes] + " ";
    }

    result += "square meters.";
    return result;
}

