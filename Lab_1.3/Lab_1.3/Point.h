#pragma once // ������� ������������� ���������� ����� ������������� �����

#include <string> // ϳ�������� ���������� �������� ��� ������ � �������

using namespace std;
class Point
{
private:
    int x = 0, y = 0;

public:
    // ������ ��� ��������� ���������
    int getX() const { return x; } // ������� ���������� X
    int getY() const { return y; } // ������� ���������� Y

    // ������ ��� ������������ ���������
    void setX(int value) { x = value; }; // ���������� ���������� X
    void setY(int value) { y = value; }; // ���������� ���������� Y

    // ����� ��� ���������� ����� �� �� X
    void moveX(int stepX);

    // ����� ��� ���������� ����� �� �� Y
    void moveY(int stepY);

    // ����� ��� ���������� ������ �� ����� �������
    double distanceFromXtoY(const Point& other) const;

    // ����������� ����� � ������������
    bool Init(int CoorX, int CoorY);

    // ��������� ��������� �����
    void Display() const;

    // ���������� ��������� ����� � ����� �����������
    void Read();

    // ���������� ����� �� ������ ������� ������� �� ����
    void displacement();

    // ������������ ��'���� �� �������� �������
    string toString(const Point& other) const;

    // ������������ ����� �� �������� �������������
    string ToNumeral(int number) const;
};
