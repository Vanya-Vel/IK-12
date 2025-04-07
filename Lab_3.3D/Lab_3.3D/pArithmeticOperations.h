#pragma once
#include "Pair.h"
#include <string>

class pArithmeticOperations : public Pair {
public:
    pArithmeticOperations& operator++();     // ���������
    pArithmeticOperations operator++(int);   // ����������
    pArithmeticOperations& operator--();     // ���������
    pArithmeticOperations operator--(int);   // ����������

    pArithmeticOperations() : Pair() {}
    pArithmeticOperations(int first, int second) : Pair(first, second) {}
    pArithmeticOperations(const Pair& p) : Pair(p) {}
};

