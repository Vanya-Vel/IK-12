#pragma once
#include "Array.h"
#include <string>

class Decimal : public Array {
public:
    Decimal();                              // ����������� �� �������������
    Decimal(const std::string& number);     // ����������� � �����

    std::string toString() const;           // ������������ � �����

    // ���������� ���������
    Decimal operator+(const Decimal& other) const;
    Decimal operator-(const Decimal& other) const;
    Decimal operator*(const Decimal& other) const;

    // ��������� ���������
    bool operator==(const Decimal& other) const;
    bool operator!=(const Decimal& other) const;
    bool operator<(const Decimal& other) const;
    bool operator<=(const Decimal& other) const;
    bool operator>(const Decimal& other) const;
    bool operator>=(const Decimal& other) const;

    // ���������
    Decimal& operator=(const Decimal& other);

    // ���/����
    friend std::istream& operator>>(std::istream& in, Decimal& d);
    friend std::ostream& operator<<(std::ostream& out, const Decimal& d);
};
