#pragma once
#include <iostream>
using namespace std;

class B1
{
    int b1; // ���� �������� �� ���� �����

public:
    // ����������� �����������
    B1(int x) : b1(x) {}

    // ����������
    ~B1() {}

    // ������� ��� ��������� ���������� ��� ����
    void show_B1()
    {
        cout << "class B1:" << endl;
        cout << "B1::b1 = " << b1 << endl << endl;
    }
};
