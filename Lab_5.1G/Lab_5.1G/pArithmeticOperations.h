#pragma once
#include "Pair.h"
#include <string>

class pArithmeticOperations : public Pair {
public:
    pArithmeticOperations& operator++();     // Префіксна
    pArithmeticOperations operator++(int);   // Постфіксна
    pArithmeticOperations& operator--();     // Префіксна
    pArithmeticOperations operator--(int);   // Постфіксна

    pArithmeticOperations() : Pair() {}
    pArithmeticOperations(int first, int second) : Pair(first, second) {}
    pArithmeticOperations(const Pair& p) : Pair(p) {}
};

