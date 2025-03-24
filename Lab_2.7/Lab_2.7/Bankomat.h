#pragma once
#include <iostream>
#include <string>
#include "Money.h"

using namespace std;

class Bankomat {
private:
    string atmID;
    Money atmMoney;
    double minWithdrawalAmount;
    double maxWithdrawalAmount;

public:
    Bankomat();
    Bankomat(string, double, double);
    Bankomat(const Bankomat&);

    bool validateATMID(string id);
    void displayBalance() const;
    void displayBalanceInWords();
    bool withdrawMoney(double amount);
    bool depositMoney(double amount);
    void showLimits();

    // �������������� ��������� �����/������
    friend ostream& operator<<(ostream& os, const Bankomat& atm);
    friend istream& operator>>(istream& is, Bankomat& atm);
};
