#include "Rectangle.h"
#include <iostream>
using namespace std;

// ����������� ������������, �������������� ���� �����
void Rectangle::Init(Rectangle::Pair sides) {
    setPair(sides);  // ��������� ����� ��� ������������ ���� �����
}

// ��������� ���������� ��� �����������: �������, �������� � �����
void Rectangle::Display() const
{
    cout << endl;
    cout << "Sides of the rectangle: " << endl;
    sides.Display();  // ������������� �����������: �������� ������� ����� ����� Pair
    cout << "Perimeter: " << getPerimeter() << endl;  // ��������� ��������� ������������
    cout << "Area: " << getArea() << endl;  // ��������� ����� ������������
}

// ���������� ����� ������������ �� �����������
void Rectangle::Read()
{
    Rectangle::Pair m;
    cout << endl;
    cout << "Enter rectangle sides: " << endl;
    m.Read();  // ������������� ����������� ��� �������� �����
    Init(m);  // ���������� ����������� ��������� ���������
}

// ����������� ���� ����� ������������
void Rectangle::Pair::Init(int first, int second)
{
    setFirst(first);  // ������������ ����� �������
    setSecond(second);  // ������������ ����� �������
}

// ��������� ����� ����
void Rectangle::Pair::Display() const
{
    cout << endl;
    cout << "First number = " << first << endl;
    cout << "Second number = " << second << endl;
}

// ���������� ����� ���� �� �����������
void Rectangle::Pair::Read()
{
    int first, second;
    cout << endl;
    cout << "First = ? "; cin >> first;
    cout << "Second = ? "; cin >> second;
    Init(first, second);  // ����������� ���� ��������� ����������
}
