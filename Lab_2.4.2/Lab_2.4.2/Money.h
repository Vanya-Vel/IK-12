#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Money {
    static const size_t MAX_SIZE = 100; // ����������� �������� ����� ������
    int summa[MAX_SIZE];  // ����� ����������� ������
    size_t size;         // ����������� ������� ��������
    size_t count;        // ������� ������� ��������

public:
    // ������������
    Money();
    Money(size_t, size_t);
    Money(const Money&);
    
    // **��������� ������ ���������� (�������)**
    size_t getSize() const { return size; }
    size_t getCount() const { return count; }
    int getData(size_t index) const {
        if (index < count) return summa[index];
        cout << "�������: ������ �������� �� ���!" << endl;
        return -1; // �������� �� ������������� � ��� �������
    }

    // **������ ������ (�������)**
    void setSize(size_t value) {
        if (value > MAX_SIZE) {
            cout << "�������: size �� ���� ���� ����� �� MAX_SIZE" << endl;
            return;
        }
        size = value;
    }
    void setCount(size_t value) {
        if (value > size) {
            cout << "�������: count �� ���� ���� ����� �� size" << endl;
            return;
        }
        count = value;
    }
    void setData(size_t index, int value) {
        if (index < count) summa[index] = value;
        else cout << "�������: ������ �������� �� ���!" << endl;
    }

    // ���������
    Money operator = (const Money&);   // ���������

    // ������������ ����� �� �������� �������������
    string toString() const;

    // ���/����
    friend ostream& operator << (ostream&, const Money&);
    friend istream& operator >> (istream&, Money&);
};
