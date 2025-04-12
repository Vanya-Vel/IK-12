#pragma once
#include "Array.h"
#include <string>

class Decimal : public Array {
public:
    Decimal();                              // Конструктор за замовчуванням
    Decimal(const std::string& number);     // Конструктор з рядка

    std::string toString() const;           // Перетворення в рядок

    // Арифметичні оператори
    Decimal operator+(const Decimal& other) const;
    Decimal operator-(const Decimal& other) const;
    Decimal operator*(const Decimal& other) const;

    // Оператори порівняння
    bool operator==(const Decimal& other) const;
    bool operator!=(const Decimal& other) const;
    bool operator<(const Decimal& other) const;
    bool operator<=(const Decimal& other) const;
    bool operator>(const Decimal& other) const;
    bool operator>=(const Decimal& other) const;

    // Присвоєння
    Decimal& operator=(const Decimal& other);

    // Ввід/вивід
    friend std::istream& operator>>(std::istream& in, Decimal& d);
    friend std::ostream& operator<<(std::ostream& out, const Decimal& d);
};
