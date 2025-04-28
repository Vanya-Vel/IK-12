#pragma once
#include "Object.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class PointException : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nError in a transaction with sides!";
    }
};

class CustomException : public std::exception {
private:
    std::string message;
public:
    CustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Pair : public Object
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

    bool Exception();

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};
