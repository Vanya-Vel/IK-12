#pragma once
#include <iostream>
#include <stdexcept>

class A {
public:
    A() { std::cout << "����������� A" << std::endl; }
    virtual ~A() { }
    virtual void display() const {
        std::cout << "���� A" << std::endl;
    }
};