#include "Money.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// ����������� Money
Money::Money(int n, unsigned char digit) : Array(n, digit) {}

// ��������� ������� ���������
void Money::add(const Array& other) {
    if (size != other.getSize()) {
        cout << "�������: ������ ���� ������ ������, ��������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
    int carry = 0;
    for (int i = 0; i < size; ++i) {
        int sum = data[i] + other[i] + carry;
        data[i] = sum % 10;
        carry = sum / 10;
    }
}

// ��������� ������� ���������
void Money::print() const {
    for (int i = size - 1; i >= 0; --i) {
        if (i == 1) cout << ",";  // ���� ����� ��������
        cout << int(data[i]);
    }
    cout << " ���" << endl;
}
