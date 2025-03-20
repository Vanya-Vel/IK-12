#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Vector
{

private:
    static const size_t MAX_SIZE = 100; // ����������� �������� ����� ������
    int data[MAX_SIZE];  // ����� ����������� ������
    size_t size;         // ����������� ������� ��������
    size_t count;        // ������� ������� ��������
    int N;

public:
    Vector();                     // ����������� �� ����������
    Vector(size_t, int);          // ����������� � ����� ����������� (�����������)
    Vector(const Vector&);        // ����������� ���������

    size_t getSize() const { return size; }
    size_t getCount() const { return count; }
    void setCount(size_t value) { 
        if (value > size) cout << "count �� ���� ���� ����� �� size" << endl;
        count = value;
    }

    double NormVector() const;
    int summa();
    string toString(double) const;                          // ������������ ����� �� �������� �������������

    Vector operator * (const Vector&);                      // �������� ��������
    bool operator == (const Vector& other) const;           // �������� ���������

    Vector& operator ++();     // ���������� ���������
    Vector operator ++(int);   // ����������� ���������
    Vector& operator --();     // ���������� ���������
    Vector operator --(int);   // ����������� ���������

    // ���/����
    friend ostream& operator << (ostream&, const Vector&);
    friend istream& operator >> (istream&, Vector&);
};