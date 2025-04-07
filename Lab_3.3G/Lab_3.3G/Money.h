#pragma once
#include <string>
#include <iostream>
#include "Object.h"

using namespace std;

class Money : public Object
{
protected:
    int fiveHundred, twoHundred, hundred, fifty, twenty, ten, five, two, one;
    int fiftyKop, twentyFiveKop, tenKop, fiveKop, twoKop, oneKop;

public:
    struct MoneyValues {
        int fh, th, h, f, t, tn, fi, tw, o;
        int fifty, twentyFive, ten, five, two, one;
    };

    Money();
    Money(const MoneyValues&);
    Money(const Money&);

    double getTotalAmount() const;
    string numberToWords(double amount) const;
    void addMoney(double amount);
    bool withdrawMoney(double amount);
    void displayBalance() const;

    // Перевантаження операторів вводу/виводу
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);

    ~Money(void);
};
