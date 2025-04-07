#include "Functions.h"
#include <iostream>

using namespace std;

// �������������� ��������� ������ ��� ��������� �� ������� � ������
ostream& operator<<(ostream& os, const Functions& functions) {
    // ��������� ���������� ��� ��������
    cout << endl;
    os << "�������� ID: " << functions.atmID << "\n";
    os << "̳������� ���� ��� ������: " << functions.minWithdrawalAmount << "\n";
    os << "����������� ���� ��� ������: " << functions.maxWithdrawalAmount << "\n";

    // ��������� ������� � ������
    double total = functions.atmMoney.getTotalAmount();
    os << "������ � ������: " << functions.atmMoney.numberToWords(total)<< endl;

    return os;
}

// �������������� ��������� ����� ��� ���������
istream& operator>>(istream& is, Functions& functions) {
    // ������� ��� ��� ���������
    cout << "������ ID ���������: ";
    is >> functions.atmID;
    cout << "������ �������� ���� ��� ������: ";
    is >> functions.minWithdrawalAmount;
    cout << "������ ����������� ���� ��� ������: ";
    is >> functions.maxWithdrawalAmount;

    return is;
}
