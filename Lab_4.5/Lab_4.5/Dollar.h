#pragma once
#include <iostream>
#include "Currency.h"

class Dollar : public Currency {
public:
    Dollar() {}

    double Exchange(double dol) const override {
        return dol * courseD;
    }

    void ExchangeDisplay(double dol) const override {
        std::cout << "Dollar to hryvna - " << Exchange(dol) << std::endl;  // ��������� ������� 1 ������
    }

    // ������ ��� ����� ������
    static double GetCourse() {
        return courseD;
    }

    // ������ ��� ����� ������
    static void SetCourse(double newCourse) {
        courseD = newCourse;
    }
};
