#pragma once

#include "Vect.h"
#include <stdexcept>

template<typename T>
class Stack {
private:
    Vect<T> vect;

public:
    Stack(size_t cap = 10) : vect(cap) {}

    void push(const T& value) {
        vect.push_back(value);
    }

    void pop() {
        vect.pop_back();
    }

    T top() const {
        if (vect.isEmpty())
            throw std::runtime_error("Stack is empty");
        return vect[vect.getSize() - 1];
    }

    bool isEmpty() const {
        return vect.isEmpty();
    }

    size_t size() const {
        return vect.getSize();
    }
};
