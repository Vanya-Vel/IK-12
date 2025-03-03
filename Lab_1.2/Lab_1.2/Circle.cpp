#include "Circle.h"
#include <iostream>

using namespace std;

void Circle::setX(int value)
{
    x = value; // ������ ��� ���������� x: �������� �������� ��������� value ����� x
}

void Circle::setY(int value)
{
    y = value; // ������ ��� ���������� y: �������� �������� ��������� value ����� y
}

void Circle::setRadius(double value)
{
    radius = value; // ������ ��� ������ ����: �������� �������� ��������� value ����� radius
}

bool Circle::Init(int x, int y, double radius)
{
    if (radius > 0) // ����������, �� ����� ����� �� ����
    {
        this->x = x;  // ���� ���, ���������� ���������� � �����
        this->y = y;
        this->radius = radius;
        return true; // ��������� true, ���� ����������� ������
    }
    else
    {
        this->x = x; // ���� ����� ����������� (������ ��� ����� ����), ���������� ����������, ��� ������� ����� ����� 0
        this->y = y;
        this->radius = 0;  // ̳������� ��������� �������� ������
        return false; // ��������� false, ���� ����������� �� �������
    }
}

void Circle::Display() const
{
    cout << " centre coordinates = (" << x << "; " << y << ")" << endl; // ��������� ��������� ������ ����
    cout << " radius = " << radius << endl; // ��������� ������ ����
}

void Circle::Read()
{
    int x, y;
    double radius;
    do {
        cout << " Coordinate x = ? "; cin >> x; // ������� x-����������
        cout << " coordinate y = ? "; cin >> y; // ������� y-����������
        cout << " Radius = ? "; cin >> radius; // ������� �����
    } while (!Init(x, y, radius)); // ���� ����������� �� ������� (����� <= 0), �������� �������� �����
}
