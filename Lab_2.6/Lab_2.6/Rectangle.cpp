#include "Rectangle.h"
#include <iostream>
#include <string>
using namespace std;

// ≤н≥ц≥ал≥зац≥€ статичних л≥чильник≥в
int Rectangle::counter = 0;
int Rectangle::Pair::counter = 0;

// –еал≥зац≥€ метод≥в класу Pair

Rectangle::Pair::Pair() : first(0), second(0) {
    counter++;  // «б≥льшуЇмо л≥чильник
}

Rectangle::Pair::Pair(int first, int second) : first(first), second(second) {
    counter++;  // «б≥льшуЇмо л≥чильник
}

Rectangle::Pair::Pair(const Pair& p) : first(p.first), second(p.second) {
    counter++;  // «б≥льшуЇмо л≥чильник
}

Rectangle::Pair::~Pair(void) {
    counter--;  // «меншуЇмо л≥чильник
}

istream& operator>>(istream& in, Rectangle::Pair& p) {
    cout << "Enter first value: ";
    in >> p.first;
    cout << "Enter second value: ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Rectangle::Pair& p) {
    out << "First = " << p.first << ", Second = " << p.second;
    return out;
}

string Rectangle::Pair::toString() const {
    return "First = " + to_string(first) + ", Second = " + to_string(second);
}

Rectangle::Pair& Rectangle::Pair::operator++() {
    first++;
    second++;
    return *this;
}

Rectangle::Pair Rectangle::Pair::operator++(int) {
    Rectangle::Pair temp = *this;
    first++;
    second++;
    return temp;
}

Rectangle::Pair& Rectangle::Pair::operator--() {
    first--;
    second--;
    return *this;
}

Rectangle::Pair Rectangle::Pair::operator--(int) {
    Rectangle::Pair temp = *this;
    first--;
    second--;
    return temp;
}

// –еал≥зац≥€ метод≥в класу Rectangle

Rectangle::Rectangle() {
    counter++;  // «б≥льшуЇмо л≥чильник
}

Rectangle::Rectangle(const Pair& sides) : sides(sides) {
    counter++;  // «б≥льшуЇмо л≥чильник
}

Rectangle::Rectangle(const Rectangle& r) : sides(r.sides) {
    counter++;  // «б≥льшуЇмо л≥чильник
}

Rectangle::~Rectangle(void) {
    counter--;  // «меншуЇмо л≥чильник
}

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
    Rectangle::Pair p;
    in >> p;
    r.setPair(p);
    return in;
}

string Rectangle::toString() const {
    int perimeter = getPerimeter();
    int area = getArea();

    const string ones[] = { "nul", "odyn", "dva", "try", "chotyry", "pТyat", "shist", "sim", "vysim", "dev'yat" };
    const string teens[] = { "desyat", "odynadtsyat", "dvanadtsyat", "trynadtsyat", "chotyrnadtsyat", "p'yatnadtsyat", "shistnadtsyat", "simnadtsyat", "vysimnadtsyat", "dev'yatnadtsyat" };
    const string tens[] = { "", "desyat", "dvadsyt", "trydtsyat", "sorok", "p'yatdesyat", "shistdesyat", "simdesyat", "vysymdesyat", "devyanosto" };
    const string hundreds[] = { "", "sto", "dvisti", "trysta", "chotyrysta", "p'yatsot", "shist'sot", "sim'sot", "vysim'sot", "dev'yatsot" };

    string result = "Perimeter: ";
    int perimeterPart = perimeter;

    // ¬изначенн€ сотень, дес€тк≥в та одиниць дл€ периметра
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

    // “епер робимо те саме дл€ площ≥
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

    return result;
}
