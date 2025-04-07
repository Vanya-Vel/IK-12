#pragma once
#include "pArithmeticOperations.h"
#include <string>

pArithmeticOperations& pArithmeticOperations::operator++() {
    setFirst(getFirst() + 1);
    setSecond(getSecond() + 1);
    return *this;
}

pArithmeticOperations pArithmeticOperations::operator++(int) {
    pArithmeticOperations temp = *this;
    setFirst(getFirst() + 1);
    setSecond(getSecond() + 1);
    return temp;
}

pArithmeticOperations& pArithmeticOperations::operator--() {
    setFirst(getFirst() - 1);
    setSecond(getSecond() - 1);
    return *this;
}

pArithmeticOperations pArithmeticOperations::operator--(int) {
    pArithmeticOperations temp = *this;
    setFirst(getFirst() - 1);
    setSecond(getSecond() - 1);
    return temp;
}
