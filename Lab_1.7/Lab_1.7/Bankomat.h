#pragma once
#include <iostream>
#include <string>
#include "Money.h"

using namespace std; // ������ ������ ���� std ��� ���������� ������

class Bankomat {
private:
    string atmID; // ����� ��� ��������� ID ���������
    Money atmMoney; // ��'��� ����� Money ��� ��������� ������� � ��������
    double minWithdrawalAmount; // ̳������� ���� ��� ������
    double maxWithdrawalAmount; // ����������� ���� ��� ������

public:
    // ����������� �� �������������
    Bankomat();

    // ����������� ���������
    void InitSet(string id, double minAmount, double maxAmount) {
        atmID = id;  // ��������� �������������� ���������
        minWithdrawalAmount = minAmount;  // ̳������� ���� ��� ������
        maxWithdrawalAmount = maxAmount;  // ����������� ���� ��� ������
    }

    // �������� ����������� ID ���������
    bool validateATMID(string id) { return id.length() == 1; }

    // ��������� �������
    void displayBalance() { atmMoney.displayBalance(); }

    // ��������� ������� � ����. ������
    void displayBalanceInWords();

    // ������ ������
    bool withdrawMoney(double amount);

    // �������� ������
    bool depositMoney(double amount);

    // ����� ���� ������
    void showLimits();
};
