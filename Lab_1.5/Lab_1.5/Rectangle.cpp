#include "Rectangle.h"
#include <iostream>
using namespace std;

void Rectangle::Init(const Pair& sides) {
	setPair(sides);  // ����������� ����� ������������ ����� ����� setPair
}

void Rectangle::Display() const
{
	cout << endl;
	cout << "Sides of the rectangle: " << endl;
	sides.Display(); // ������������� ����������� ��� ��������� ����� ������������
	cout << "Perimeter: " << getPerimeter() << endl;  // ��������� ���������
	cout << "Area: " << getArea() << endl;  // ��������� �����
}

void Rectangle::Read()
{
	Pair m;
	cout << endl;
	cout << "Enter rectangle sides: " << endl;
	m.Read(); // ������������� ����������� ��� �������� ������� ����
	Init(m);  // ����������� ������������ ���������� ���������� �����
}
