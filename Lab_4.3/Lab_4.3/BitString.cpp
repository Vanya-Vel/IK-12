#include "BitString.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Конструктор BitString
BitString::BitString(int n, unsigned char bit) : Array(n, bit) {
    for (int i = 0; i < size; ++i) {
        if (data[i] != 0 && data[i] != 1) {
            cout << "Помилка: бітовий масив може містити лише 0 або 1!" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

// Реалізація функції додавання
void BitString::add(const Array& other) {
    if (size != other.getSize()) {
        cout << "Помилка: бітові рядки різного розміру, додавання неможливе!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] = data[i] | other[i];
    }
}

// Операція AND
void BitString::bitwise_and(const BitString& other) {
    if (size != other.getSize()) {
        cout << "Помилка: операція AND для рядків різної довжини неможлива!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] &= other[i];
    }
}

// Операція OR
void BitString::bitwise_or(const BitString& other) {
    if (size != other.getSize()) {
        cout << "Помилка: операція OR для рядків різної довжини неможлива!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] |= other[i];
    }
}

// Операція XOR
void BitString::bitwise_xor(const BitString& other) {
    if (size != other.getSize()) {
        cout << "Помилка: операція XOR для рядків різної довжини неможлива!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] ^= other[i];
    }
}

// Операція NOT
void BitString::bitwise_not() {
    for (int i = 0; i < size; ++i) {
        data[i] = !data[i];
    }
}

// Зсув вліво
void BitString::shift_left(int count) {
    if (count < 0 || count > size) {
        cout << "Помилка: неправильний зсув вліво!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = size - 1; i >= count; --i) {
        data[i] = data[i - count];
    }
    for (int i = 0; i < count; ++i) {
        data[i] = 0;
    }
}

// Зсув вправо
void BitString::shift_right(int count) {
    if (count < 0 || count > size) {
        cout << "Помилка: неправильний зсув вправо!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size - count; ++i) {
        data[i] = data[i + count];
    }
    for (int i = size - count; i < size; ++i) {
        data[i] = 0;
    }
}

// Виведення бітового рядка
void BitString::print() const {
    for (int i = size - 1; i >= 0; --i) {
        cout << int(data[i]);
    }
    cout << " (бітовий рядок)" << endl;
}
