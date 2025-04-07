#include "Pair.h"

Pair::Pair() : first(0), second(0) {}

Pair::Pair(int first, int second) : first(first), second(second) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

istream& operator>>(istream& in, Pair& p) {
    cout << "Enter first value: ";
    in >> p.first;
    cout << "Enter second value: ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "First = " << p.first << ", Second = " << p.second;
    return out;
}
