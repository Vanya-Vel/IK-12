#pragma once
#include "Array.h"

class BitString : public Array {
public:
    BitString(int n = 10, unsigned char bit = 0);

    void add(const Array& other) override;
    void bitwise_and(const BitString& other);
    void bitwise_or(const BitString& other);
    void bitwise_xor(const BitString& other);
    void bitwise_not();
    void shift_left(int count);
    void shift_right(int count);
    void print() const override;
};
