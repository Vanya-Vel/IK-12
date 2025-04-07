#pragma once
#include "pArithmeticOperations.h"

class pFunctions : public pArithmeticOperations {
public:
    int multiply() const { return first * second; }

    pFunctions() : pArithmeticOperations() {}
    pFunctions(int first, int second) : pArithmeticOperations(first, second) {}
    pFunctions(const pArithmeticOperations& p) : pArithmeticOperations(p) {}
};
