#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "Object.h"

using namespace std;

// ��������� �� ����� �������
class ErrorID : public std::exception {
public:
    const char* what() const noexcept override {
        return "\n������� ������������� (�� ���� 29 ����)!";
    }
};

class ErrorWithdrawal : public std::exception {
public:
    const char* what() const noexcept override {
        return "\n������� ��� ���������!";
    }
};

class ErrorChoise : public std::exception {
public:
    const char* what() const noexcept override {
        return "\n������� ������!";
    }
};

class ErrorAmount : public std::exception {
public:
    const char* what() const noexcept override {
        return "\n������� ������� �������!";
    }
};

class ErrorBalance : public std::exception {
public:
    const char* what() const noexcept override {
        return "\n�������: ����������� ����� �� ������!";
    }
};

// ���� Money
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

    // �������������� ��������� �����/������
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);
};
