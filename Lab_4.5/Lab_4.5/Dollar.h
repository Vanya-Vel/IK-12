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
        std::cout << "Dollar to hryvna - " << Exchange(dol) << std::endl;  // Виведення вартості 1 долара
    }

    // Геттер для курсу долара
    static double GetCourse() {
        return courseD;
    }

    // Сеттер для курсу долара
    static void SetCourse(double newCourse) {
        courseD = newCourse;
    }
};
