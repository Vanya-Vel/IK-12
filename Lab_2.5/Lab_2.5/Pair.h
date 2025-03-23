#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair {
private:
    int first, second;

public:
    Pair();  // ����������� ��� ���������
    Pair(int first, int second);  // ����������� � �����������
    Pair(const Pair& p);  // ����������� ���������

    // �������� �������
    int getFirst() const;
    void setFirst(int first);
    int getSecond() const;
    void setSecond(int second);

    // ����� ��� ���������� �������
    int multiply() const;

    // ��������� �������
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);

    // ������������ � �����
    string toString() const;

    // �������� ���������� (���������)
    Pair& operator++();

    // �������� ���������� (����������)
    Pair operator++(int);

    // �������� ���������� (���������)
    Pair& operator--();

    // �������� ���������� (����������)
    Pair operator--(int);
};
