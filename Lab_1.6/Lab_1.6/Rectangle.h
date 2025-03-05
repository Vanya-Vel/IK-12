#pragma once
#include <string>
using namespace std;

class Rectangle
{
private:
    // ��������� ���� ��� ���� ����� ������������
    class Pair
    {
    private:
        int first, second;  // ����� � ����� �������

    public:
        // ������� �� ������� ��� ����� ������������
        int getFirst() const { return first; }
        void setFirst(int first) { this->first = first; }
        int getSecond() const { return second; }
        void setSecond(int second) { this->second = second; }

        // ���������� ������� �����
        int multiply() const { return first * second; }

        // ����������� ���� �����
        void Init(int first, int second);

        // ��������� �����
        void Display() const;

        // ���������� �����
        void Read();
    };

    // ������ ���� ����� ������������
    Pair sides;

public:
    // ������ � ������ ��� ���� �����
    Rectangle::Pair getPair() const { return sides; }
    void setPair(Rectangle::Pair sides) { this->sides = sides; }

    // ���������� ��������� ������������
    int getPerimeter() const { return 2 * (sides.getFirst() + sides.getSecond()); }

    // ���������� ����� ������������
    int getArea() const { return sides.multiply(); }

    // ����������� ������������
    void Init(Rectangle::Pair sides);

    // ��������� ���������� ��� �����������
    void Display() const;

    // ���������� ����� ������������
    void Read();
};
