#pragma once
#include <iostream>
#include "Currency.h"

class Euro : public Currency {
public:
    Euro() {}

    double Exchange(double eu) const override {
        return eu * courseE;
    }

    void ExchangeDisplay(double eu) const override {
        std::cout << "Euro to hryvna - " << Exchange(eu) << std::endl;
    }
    // ������ ��� ����� ����
    static double GetCourse() {
        return courseE;
    }

    // ������ ��� ����� ����
    static void SetCourse(double newCourse) {
        courseE = newCourse;
    }
};
