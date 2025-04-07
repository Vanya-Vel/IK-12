#pragma once
#include <string>
#include "Bankomat.h"

using namespace std;

class Functions : public Bankomat {
public:
    // �������������� ��������� ������ ��� ���������
    friend ostream& operator<<(ostream& os, const Functions& functions);

    // �������������� ��������� ����� ��� ���������
    friend istream& operator>>(istream& is, Functions& functions);

    // �������������� ��������� ������ ��� ������� � ������
    friend ostream& operator<<(ostream& os, const Functions& functions);

    Functions() : Bankomat() {}
    Functions(string id, double minAmount, double maxAmount) : Bankomat(id, minAmount, maxAmount) {}
    Functions(const Bankomat& other) : Bankomat(other) {}
};
