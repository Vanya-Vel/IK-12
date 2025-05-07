#pragma once

#include <stdexcept>

template<typename T>
class Vect {
private:
    T* data;
    size_t capacity;
    size_t size;

public:
    Vect(size_t cap = 10) : capacity(cap), size(0) {
        if (capacity == 0)
            throw std::invalid_argument("Capacity must be > 0");
        data = new T[capacity];
    }

    ~Vect() {
        delete[] data;
    }

    // Заборона копіювання (опціонально, або реалізуйте Rule of 3)
    Vect(const Vect&) = delete;
    Vect& operator=(const Vect&) = delete;

    void push_back(const T& value) {
        if (size >= capacity)
            throw std::overflow_error("Vect overflow");
        data[size++] = value;
    }

    void pop_back() {
        if (size == 0)
            throw std::underflow_error("Vect underflow");
        --size;
    }

    T& operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    size_t getSize() const { return size; }

    bool isEmpty() const { return size == 0; }
};
