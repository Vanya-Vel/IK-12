#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair
{
protected:
    int first, second;

public:
    Pair();
    Pair(int first, int second);
    Pair(const Pair& p);

    int getFirst() const { return first; }
    void setFirst(int first) { this->first = first; }

    int getSecond() const { return second; }
    void setSecond(int second) { this->second = second; }

    string toString() const {
        return "First = " + to_string(first) + ", Second = " + to_string(second);
    }

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};
