#pragma once
#include <iostream>
#include "Money.h"
using namespace std;

class Bankomat : public Money, public Object {
protected:
    std::string atmID;
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

    // Перевантаження операторів вводу/виводу
    friend ostream& operator<<(ostream& os, const Bankomat& atm);
    friend istream& operator>>(istream& is, Bankomat& atm);

    ~Bankomat(void);
};
