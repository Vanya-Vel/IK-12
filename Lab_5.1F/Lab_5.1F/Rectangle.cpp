#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() {}

Rectangle::Rectangle(const Pair& sides) : sides(sides) {}

Rectangle::Rectangle(const Rectangle& r) : sides(r.sides) {}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        sides = r.sides;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    out << "Rectangle sides: " << r.sides.toString() << std::endl;
    out << "Perimeter: " << r.getPerimeter() << std::endl;
    out << "Area: " << r.getArea() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Rectangle& r) {
    Pair p;
    in >> p;
    r.setPair(p);
    return in;
}

std::string Rectangle::toString() const {
    int perimeter = getPerimeter();
    int area = getArea();

    const std::string ones[] = { "nul", "odyn", "dva", "try", "chotyry", "p’yat", "shist", "sim", "vysim", "dev'yat" };
    const std::string teens[] = { "desyat", "odynadtsyat", "dvanadtsyat", "trynadtsyat", "chotyrnadtsyat", "p'yatnadtsyat", "shistnadtsyat", "simnadtsyat", "vysimnadtsyat", "dev'yatnadtsyat" };
    const std::string tens[] = { "", "desyat", "dvadsyt", "trydtsyat", "sorok", "p'yatdesyat", "shistdesyat", "simdesyat", "vysymdesyat", "devyanosto" };
    const std::string hundreds[] = { "", "sto", "dvisti", "trysta", "chotyrysta", "p'yatsot", "shist'sot", "sim'sot", "vysim'sot", "dev'yatsot" };

    std::string result = "Perimeter: ";
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
