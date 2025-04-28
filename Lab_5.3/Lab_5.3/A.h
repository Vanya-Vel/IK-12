#pragma once
#include <iostream>
#include <stdexcept>

class A {
public:
    A() { std::cout << "Конструктор A" << std::endl; }
    virtual ~A() { }
    virtual void display() const {
        std::cout << "Клас A" << std::endl;
    }
};