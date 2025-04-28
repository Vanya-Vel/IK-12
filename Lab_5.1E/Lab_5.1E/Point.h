#pragma once
#include "Object.h" 
#include <string>
#include <istream>
using namespace std;

// ���������� �������� �������
class PointException : public exception {
public:
    const char* what() const noexcept override {
        return "������� � ��������� � ������!";
    }
};

class Point : public Object
{
protected:
    int x, y;

public:
    Point();                    // ����������� �� ����������
    Point(int, int);            // ����������� � ����� ����������� (�����������)
    Point(const Point&);        // ����������� ���������

    bool operator > (const Point&) const;

    // ��������/���������
    friend ostream& operator << (ostream&, const Point&);
    friend istream& operator >> (istream&, Point&);
};

