#include "Money.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Конструктор Money
Money::Money(int n, unsigned char digit) : Array(n, digit) {}

// Реалізація функції додавання
void Money::add(const Array& other) {
    if (size != other.getSize()) {
        cout << "Помилка: грошові суми різного розміру, додавання неможливе!" << endl;
        exit(EXIT_FAILURE);
    }
    int carry = 0;
    for (int i = 0; i < size; ++i) {
        int sum = data[i] + other[i] + carry;
        data[i] = sum % 10;
        carry = sum / 10;
    }
}

// Реалізація функції виведення
void Money::print() const {
    for (int i = size - 1; i >= 0; --i) {
        if (i == 1) cout << ",";  // кома перед копійками
        cout << int(data[i]);
    }
    cout << " грн" << endl;
}
