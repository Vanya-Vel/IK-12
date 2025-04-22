#include "BitString.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// ����������� BitString
BitString::BitString(int n, unsigned char bit) : Array(n, bit) {
    for (int i = 0; i < size; ++i) {
        if (data[i] != 0 && data[i] != 1) {
            cout << "�������: ������ ����� ���� ������ ���� 0 ��� 1!" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

// ��������� ������� ���������
void BitString::add(const Array& other) {
    if (size != other.getSize()) {
        cout << "�������: ���� ����� ������ ������, ��������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] = data[i] | other[i];
    }
}

// �������� AND
void BitString::bitwise_and(const BitString& other) {
    if (size != other.getSize()) {
        cout << "�������: �������� AND ��� ����� ���� ������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] &= other[i];
    }
}

// �������� OR
void BitString::bitwise_or(const BitString& other) {
    if (size != other.getSize()) {
        cout << "�������: �������� OR ��� ����� ���� ������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] |= other[i];
    }
}

// �������� XOR
void BitString::bitwise_xor(const BitString& other) {
    if (size != other.getSize()) {
        cout << "�������: �������� XOR ��� ����� ���� ������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        data[i] ^= other[i];
    }
}

// �������� NOT
void BitString::bitwise_not() {
    for (int i = 0; i < size; ++i) {
        data[i] = !data[i];
    }
}

// ���� ����
void BitString::shift_left(int count) {
    if (count < 0 || count > size) {
        cout << "�������: ������������ ���� ����!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = size - 1; i >= count; --i) {
        data[i] = data[i - count];
    }
    for (int i = 0; i < count; ++i) {
        data[i] = 0;
    }
}

// ���� ������
void BitString::shift_right(int count) {
    if (count < 0 || count > size) {
        cout << "�������: ������������ ���� ������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size - count; ++i) {
        data[i] = data[i + count];
    }
    for (int i = size - count; i < size; ++i) {
        data[i] = 0;
    }
}

// ��������� ������� �����
void BitString::print() const {
    for (int i = size - 1; i >= 0; --i) {
        cout << int(data[i]);
    }
    cout << " (������ �����)" << endl;
}
