#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846 // �������������� �������� ����� ϳ, ���� ���� �� ���������
#endif
#include <string>

using namespace std;

class Circle
{
private:
    int x, y; // ���������� ������ ����
    double radius; // ����� ����
public:
    int getX() const { return x; } // ������ ��� x-����������
    int getY() const { return y; } // ������ ��� y-����������
    double getRadius() const { return radius; } // ������ ��� ������ ����
    void setX(int value) { x = value; } // ������ ��� x-����������
    void setY(int value) { y = value; } // ������ ��� y-����������
    void setRadius(double value) { radius = value; } // ������ ��� ������ ����

    bool Init(int x, int y, double radius); // ����� ��� ����������� ��������� � ������ ����
    double AreaOfCircle() const { return M_PI * radius * radius; } // ����� ��� ���������� ����� ����
    double CircleLength() const { return 2 * M_PI * radius; } // ����� ��� ���������� ������� ����

    void Display() const; // ����� ��� ��������� ���������� ��� ����
    void Read(); // ����� ��� ���������� ��������� ���� �� �����������
};
