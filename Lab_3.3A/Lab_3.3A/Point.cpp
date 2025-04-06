#include "Point.h"
#include <cmath>  
#include <iostream>

using namespace std;

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int coorX, int coorY) {
    this->x = coorX;
    this->y = coorY;
}

Point::Point(const Point& other) {
    x = other.x;
    y = other.y;
}

ostream& operator << (ostream& out, const Point& other) {
    out << "Координати: (" << other.x << ", " << other.y << ")";
    return out;
}

istream& operator >> (istream& in, Point& other) {
    cout << "Enter starting coordinates (x, y): ";
    in >> other.x >> other.y;
    return in;
}
