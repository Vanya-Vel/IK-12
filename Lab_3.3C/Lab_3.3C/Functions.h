#pragma once
#include "ArithmeticOperations.h"
#include <cmath>

class Functions : public ArithmeticOperations
{
public:
    // ����� ��� ���������� ����� �� �� X
    void moveX(int stepX) { x += stepX; }

    // ����� ��� ���������� ����� �� �� Y
    void moveY(int stepY) { y += stepY; }

    int getX() const { return x; }
    int getY() const { return y; }

    // ����� ��� ���������� ������ �� ����� �������
    double distanceFromXtoY(const Functions& other) const;

    // ������������ ��'���� �� �������� �������
    string toString(const Functions& other) const;

    // ������������ ����� �� �������� �������������
    string ToNumeral(double number) const;

    // ����������� �� ����������
    Functions() : ArithmeticOperations() {}
    // ����������� � �����������
    Functions(int y, int x) : ArithmeticOperations(x, y) {}
    // ����������� ���������
    Functions(const Functions& other) : ArithmeticOperations(other) {}
};

