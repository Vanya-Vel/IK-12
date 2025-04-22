#pragma once
#include "ABase.h"
#include <iostream>

class ArithmeticProg : public ABase {
private:
    double first;
    double difference;

public:
    ArithmeticProg(double a0, double d) : first(a0), difference(d) {}

    double sum_progression(int n) override {
        double an = first + (static_cast<double>(n) - 1) * difference;
        double sum = (n * (first + an)) / 2;
        return sum;
    }
};
