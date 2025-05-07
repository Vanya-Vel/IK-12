#pragma once
#include <stdexcept>
#include <iostream>

template <class T, std::size_t N>
class Array {
public:
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;

    static const size_type static_size = N;

    Array(const T& t = T()); // конструктор

    size_type size() const {
        return static_size;
    }

    reference operator[] (const size_type& i) {
        rangecheck(i);
        return elem[i];
    }

    const_reference operator[] (const size_type& i) const {
        rangecheck(i);
        return elem[i];
    }

    // Дружні функції введення/виведення
    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        for (size_type i = 0; i < arr.size(); ++i)
            os << arr[i] << " ";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Array& arr) {
        for (size_type i = 0; i < arr.size(); ++i)
            is >> arr[i];
        return is;
    }

    // Пошук елемента
    int find(const T& value) const {
        for (size_type i = 0; i < size(); ++i)
            if (elem[i] == value)
                return static_cast<int>(i);
        return -1; // not found
    }

    // Арифметичні операції
    Array<T, N> operator+(const T& value) const {
        Array<T, N> result;
        for (size_type i = 0; i < size(); ++i)
            result[i] = elem[i] + value;
        return result;
    }

    Array<T, N>& operator+=(const T& value) {
        for (size_type i = 0; i < size(); ++i)
            elem[i] += value;
        return *this;
    }

    // Ітератори
    T* begin() { return &elem[0]; }
    T* end() { return &elem[0] + N; }
    const T* begin() const { return &elem[0]; }
    const T* end() const { return &elem[0] + N; }

private:
    void rangecheck(const size_type& i) const {
        if (i >= size())
            throw std::range_error("Array: index out of range!");
    }

    T elem[N];
};

// Реалізація конструктора
template <class T, std::size_t N>
Array<T, N>::Array(const T& t) {
    for (int i = 0; i < N; i++)
        elem[i] = t;
}
