#include "Array.h"

// ��������� ������������
Array::Array(int n, unsigned char value) {
    if (n > MAX_SIZE) {
        cout << "�������: ���������� ������������ ����� ������!" << endl;
        exit(EXIT_FAILURE);
    }
    size = n;
    for (int i = 0; i < size; ++i)
        data[i] = value;
}

// ����������
Array::~Array() {}

// ��������� ��������� �������
unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return data[index];
}

// ��������� ������� ���������
void Array::add(const Array& other) {
    if (size != other.getSize()) {
        cout << "�������: ������ ������ ������, ��������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i)
        data[i] += other[i];
}

// ��������� ������� ���������
void Array::print() const {
    for (int i = size - 1; i >= 0; --i)
        cout << int(data[i]);
    cout << endl;
}

// ��������� ������� ��������� ������
int Array::getSize() const {
    return size;
}

// ��������� ������� �������� ��������
void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        cout << "�������: ������ ���� ���������� ���������!" << endl;
        exit(EXIT_FAILURE);
    }
}
