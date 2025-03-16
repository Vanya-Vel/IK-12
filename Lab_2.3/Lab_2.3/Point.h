#pragma once
#include <string>
#include <istream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point();                    // ����������� �� ����������
    Point(int, int);            // ����������� � ����� ����������� (�����������)
    Point(const Point&);        // ����������� ���������

    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    // ����� ��� ���������� ����� �� �� X
    void moveX(int stepX) { x += stepX; }

    // ����� ��� ���������� ����� �� �� Y
    void moveY(int stepY) { y += stepY; }

    // ����� ��� ���������� ������ �� ����� �������
    double distanceFromXtoY(const Point& other) const;

    // ������������ ��'���� �� �������� �������
    string toString(const Point& other) const;

    // ������������ ����� �� �������� �������������
    string ToNumeral(double number) const;

    Point operator + (const Point&);        // �������� ��������� �����
    Point& operator = (const Point&);       // �������� ���������

    Point& operator ++();     // ���������� ���������
    Point& operator --();     // ���������� ���������
    Point operator ++(int);   // ����������� ���������
    Point operator --(int);   // ����������� ���������

    // ���� ����� � ����
    friend ostream& operator << (ostream&, const Point&);

    // �������� ����� � ������
    friend istream& operator >> (istream&, Point&);
};

