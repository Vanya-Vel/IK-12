#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "Object.h"

using namespace std;

// Стандартні та власні винятки
class ErrorID : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nПомилка ідентифікації (має бути 29 цифр)!";
    }
};

class ErrorWithdrawal : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nПомилка меж виведення!";
    }
};

class ErrorChoise : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nПомилка вибору!";
    }
};

class ErrorAmount : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nПомилка кількості номіналів!";
    }
};

class ErrorBalance : public std::exception {
public:
    const char* what() const noexcept override {
        return "\nПомилка: недостатньо коштів на балансі!";
    }
};

// Клас Money
class Money : public Object {
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
};
