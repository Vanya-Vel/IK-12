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
    void Init(string id, double minAmount, double maxAmount);

    // �������� ����������� ID ���������
    bool validateATMID(string id);

    // ��������� �������
    void displayBalance();

    // ��������� ������� � ����. ������
    void displayBalanceInWords();

    // ������ ������
    bool withdrawMoney(double amount);

    // �������� ������
    bool depositMoney(double amount);

    // ����� ���� ������
    void showLimits();
};
