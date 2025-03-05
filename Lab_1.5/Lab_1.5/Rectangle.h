#pragma once
#include <string>
#include "Pair.h"
using namespace std;

class Rectangle
{
private:
	Pair sides;  // ����������� ������� ������������

public:
	// ��������� ���� ����� ������������
	Pair getPair() const { return sides; }

	// ������������ ����� ������� �����
	void setPair(const Pair& sides) { this->sides = sides; }

	// ���������� ��������� ������������
	int getPerimeter() const { return 2 * (sides.getFirst() + sides.getSecond()); }

	// ���������� ����� ������������
	int getArea() const { return sides.multiply(); }

	// ����������� ����� ������������
	void Init(const Pair& sides);

	// ��������� ���������� ��� �����������
	void Display() const;

	// ������� ������� ����� ������������
	void Read();
};
