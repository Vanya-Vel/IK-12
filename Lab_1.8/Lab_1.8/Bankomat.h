#pragma once
using namespace std; // ������ ������ ���� std ��� ���������� ������
#include <string>

class Bankomat
{
public:
    // ���������� ����������� ����� Money
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

private:
    string atmID; // ����� ��� ��������� ID ���������
    Money atmMoney; // ��'��� ����� Money ��� ��������� ������� � ��������
    double minWithdrawalAmount; // ̳������� ���� ��� ������
    double maxWithdrawalAmount; // ����������� ���� ��� ������

public:
    // ����������� �� �������������
    Bankomat();

    // ������ ��� �������� ����
    double getMinWithdrawalAmount() const {
        return minWithdrawalAmount;
    }

    // ������ ��� ����������� ����
    double getMaxWithdrawalAmount() const {
        return maxWithdrawalAmount;
    }

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
