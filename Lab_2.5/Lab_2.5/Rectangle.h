#pragma once
#include "Pair.h"
#include <iostream>
using namespace std;

class Rectangle {
private:
    Pair sides;

public:
    Rectangle();  // ����������� ��� ���������
    Rectangle(const Pair& sides);  // ����������� � �����������
    Rectangle(const Rectangle& r);  // ����������� ���������

    // ������ �������
    Pair getPair() const;
    void setPair(const Pair& sides);

    // ���������� ���������
    int getPerimeter() const;

    // ���������� �����
    int getArea() const;

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
