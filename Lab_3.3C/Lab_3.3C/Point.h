#pragma once
#include "Object.h"
#include <string>
#include <istream>
using namespace std;

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

