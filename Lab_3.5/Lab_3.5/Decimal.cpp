#include "Decimal.h"
#include <algorithm>
#include <iostream>

Decimal::Decimal() : Array(1, 0) {}

Decimal::Decimal(const std::string& number) {
    if (number.empty() || number.length() > MAX_SIZE || !std::all_of(number.begin(), number.end(), ::isdigit)) {
        std::cerr << "Помилка: некоректне число!\n";
        std::exit(1);
    }
    size = number.length();
    for (int i = 0; i < size; ++i)
        data[i] = number[size - 1 - i] - '0';
}

std::string Decimal::toString() const {
    std::string result;
    for (int i = size - 1; i >= 0; --i)
        result += static_cast<char>(data[i] + '0');
    return result;
}

Decimal Decimal::operator+(const Decimal& other) const {
    Decimal result;
    int carry = 0, i = 0;
    int maxSize = std::max(size, other.size);

    for (; i < maxSize || carry; ++i) {
        int sum = carry;
        if (i < size) sum += data[i];
        if (i < other.size) sum += other.data[i];
        result.data[i] = sum % 10;
        carry = sum / 10;
    }
    result.size = i;
    return result;
}

Decimal Decimal::operator-(const Decimal& other) const {
    if (*this < other) {
        std::cerr << "Помилка: від’ємний результат.\n";
        std::exit(1);
    }
    Decimal result;
    int borrow = 0;
    for (int i = 0; i < size; ++i) {
        int diff = data[i] - borrow - (i < other.size ? other.data[i] : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result.data[i] = diff;
    }
    result.size = size;
    while (result.size > 1 && result.data[result.size - 1] == 0)
        --result.size;
    return result;
}

Decimal Decimal::operator*(const Decimal& other) const {
    Decimal result;
    result.size = size + other.size;
    std::fill(result.data, result.data + result.size, 0);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < other.size; ++j) {
            result.data[i + j] += data[i] * other.data[j];
            if (result.data[i + j] >= 10) {
                result.data[i + j + 1] += result.data[i + j] / 10;
                result.data[i + j] %= 10;
            }
        }

    while (result.size > 1 && result.data[result.size - 1] == 0)
        --result.size;
    return result;
}

bool Decimal::operator==(const Decimal& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i)
        if (data[i] != other.data[i]) return false;
    return true;
}

bool Decimal::operator!=(const Decimal& other) const {
    return !(*this == other);
}

bool Decimal::operator<(const Decimal& other) const {
    if (size != other.size) return size < other.size;
    for (int i = size - 1; i >= 0; --i)
        if (data[i] != other.data[i]) return data[i] < other.data[i];
    return false;
}

bool Decimal::operator<=(const Decimal& other) const {
    return *this < other || *this == other;
}

bool Decimal::operator>(const Decimal& other) const {
    return !(*this <= other);
}

bool Decimal::operator>=(const Decimal& other) const {
    return !(*this < other);
}

Decimal& Decimal::operator=(const Decimal& other) {
    if (this != &other) {
        size = other.size;
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Decimal& d) {
    std::string s;
    in >> s;
    d = Decimal(s);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Decimal& d) {
    out << d.toString();
    return out;
}
