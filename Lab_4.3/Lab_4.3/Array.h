#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

    void rangeCheck(int index) const;

public:
    Array(int n = 10, unsigned char value = 0);
    virtual ~Array();

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    virtual void add(const Array& other);
    virtual void print() const;

    int getSize() const;
};
