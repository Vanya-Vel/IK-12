#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bankomat
{
public:
    class Money {
    private:
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
    };

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

    // Перевантаження операторів вводу/виводу
    friend ostream& operator<<(ostream& os, const Bankomat& atm);
    friend istream& operator>>(istream& is, Bankomat& atm);


};

