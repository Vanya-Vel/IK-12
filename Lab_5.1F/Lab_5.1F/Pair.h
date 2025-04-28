#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class PointException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error in a transaction with sides!";
    }
};


class Pair {
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

    std::string toString() const;

    bool Exception();

    friend std::istream& operator>>(std::istream& in, Pair& p);
    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
};
