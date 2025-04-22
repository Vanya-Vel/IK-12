#pragma once
#include "Array.h"

class Money : public Array {
public:
    Money(int n = 10, unsigned char digit = 0);

    void add(const Array& other) override;
    void print() const override;
};
