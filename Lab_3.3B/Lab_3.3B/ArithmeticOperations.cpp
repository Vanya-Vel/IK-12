#include "ArithmeticOperations.h"

// ���������� ���������
ArithmeticOperations& ArithmeticOperations::operator ++() {
    ++x;  // �������� x
    return *this;
}

// ���������� ���������
ArithmeticOperations& ArithmeticOperations::operator --() {
    --y;  // �������� y
    return *this;
}

// ����������� ���������
ArithmeticOperations ArithmeticOperations::operator ++(int) {
    ArithmeticOperations temp(*this);  // �������� �������� ����
    x++;  // �������� x
    return temp;
}

// ����������� ���������
ArithmeticOperations ArithmeticOperations::operator --(int) {
    ArithmeticOperations temp(*this);  // �������� �������� ����
    --y;  // �������� y
    return temp;
}

// �������� ���������
ArithmeticOperations ArithmeticOperations::operator + (const ArithmeticOperations& other) {
    return ArithmeticOperations(x + other.x, y + other.y);  // ������ ������� ����������
}

// �������� ���������
ArithmeticOperations& ArithmeticOperations::operator = (const ArithmeticOperations& other) {
    if (this != &other) {  // �������� �� �������������
        x = other.x;
        y = other.y;
    }
    return *this;
}
