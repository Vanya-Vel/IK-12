#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

class Rectangle : public Pair
{

public:
    Rectangle();  // ����������� ��� ���������
    Rectangle(const Pair& sides);  // ����������� � �����������
    Rectangle(const Rectangle& r);  // ����������� ���������

    // ������ �������
    Pair getPair() const {
        return Pair(getFirst(), getSecond());
    }

    void setPair(const Pair& sides) {
        setFirst(sides.getFirst());
        setSecond(sides.getSecond());
    }

    // ���������� ���������
    int getPerimeter() const {
        return 2 * (getFirst() + getSecond());
    }

    // ���������� �����
    int getArea() const { return multiply(); }

    // �������� ���������
    Rectangle& operator=(const Rectangle& r);

    // �������� ���������� � ����������
    Rectangle& operator++();  // �������
    Rectangle operator++(int);  // ��������
    Rectangle& operator--();  // �������
    Rectangle operator--(int);  // ��������

    // ��������� �������
    friend ostream& operator<<(ostream& out, const Rectangle& r);

    // �������� �������
    friend istream& operator>>(istream& in, Rectangle& r);

    // ������������ � ��������� ������
    string toString() const;
};
