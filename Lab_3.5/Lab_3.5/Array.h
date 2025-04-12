#pragma once
#include <iostream>

class Array {
protected:
    static const int MAX_SIZE = 100;       // Максимальний розмір масиву
    unsigned char data[MAX_SIZE]{};        // Масив цифр
    int size;                              // Поточний розмір

    

public:
    Array(int size = 1, unsigned char init = 0) {
        if (size < 1 || size > MAX_SIZE) {
            std::cerr << "Помилка: некоректний розмір масиву.\n";
            std::exit(1);
        }
        this->size = size;
        std::fill(data, data + size, init);
    }

    unsigned char& operator[](int index) {
        rangeCheck(index);
        return data[index];
    }

    const unsigned char& operator[](int index) const {
        rangeCheck(index);
        return data[index];
    }

    int getSize() const { return size; }
    void setSize(int newSize) {
        if (newSize < 1 || newSize > MAX_SIZE) {
            std::cerr << "Помилка: некоректний розмір.\n";
            std::exit(1);
        }
        size = newSize;
    }

    bool rangeCheck(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Помилка: індекс виходить за межі діапазону.\n";
            return false;
        }
        return true;
    }
};
