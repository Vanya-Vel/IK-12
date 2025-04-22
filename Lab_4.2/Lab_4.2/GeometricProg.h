#pragma once
#include "ABase.h"
#include <iostream>
#include <cmath>

class GeometricProg : public ABase {
private:
    double first;
    double ratio;

public:
    GeometricProg(double a0, double r) : first(a0), ratio(r) {}

    double sum_progression(int n) override {
        double an = first * pow(ratio, n);
        if (ratio == 1) {
            return first * n;
        }
        double sum = (first - an * ratio) / (1 - ratio);
        return sum;
    }
};
