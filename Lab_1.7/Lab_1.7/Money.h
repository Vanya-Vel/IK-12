#pragma once
#include <string>
#include <iostream>

using namespace std; // ������ ������ ���� std ��� ���������� ������

class Money {
private:
    // ���� ��� ������� ������� ������� (����� �� ������)
    int fiveHundred, twoHundred, hundred, fifty, twenty, ten, five, two, one;
    int fiftyKop, twentyFiveKop, tenKop, fiveKop, twoKop, oneKop;

public:
    // ����������� �� �������������
    Money();

    // ����������� ������ (������� ��������� ������� ����� �� �����)
    void initMoney(int fh, int th, int h, int f, int t, int tn, int fi, int tw, int o, int fifty, int twentyFive, int ten, int five, int two, int one);

    // ������� ���� � ������� (����� �� ������)
    double getTotalAmount() const;

    // ������������ ���� � ��������� ������ (����� �� ������)
    string numberToWords(double amount) const;

    // ��������� ������� (����� �� ������)
    void displayBalance() const;

    // �������� ��������� ������ (������ ����� ����)
    void addMoney(double amount);

    // �������� ������ ������ (������ ����� ����)
    bool withdrawMoney(double amount);
};
