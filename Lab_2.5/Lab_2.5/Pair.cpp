#include "Pair.h"

Pair::Pair() : first(0), second(0) {}

Pair::Pair(int first, int second) : first(first), second(second) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

int Pair::getFirst() const { return first; }
void Pair::setFirst(int first) { this->first = first; }

int Pair::getSecond() const { return second; }
void Pair::setSecond(int second) { this->second = second; }

int Pair::multiply() const { return first * second; }

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

string Pair::toString() const {
    return "First = " + to_string(first) + ", Second = " + to_string(second);
}

Pair& Pair::operator++() {
    first++;
    second++;
    return *this;
}

Pair Pair::operator++(int) {
    Pair temp = *this;
    first++;
    second++;
    return temp;
}

Pair& Pair::operator--() {
    first--;
    second--;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp = *this;
    first--;
    second--;
    return temp;
}
