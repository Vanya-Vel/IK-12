#include "Money.h"

using namespace std; // ������ ������ ���� std ��� ���������� ������

// ����������� ������ (������� ��������� ������� ����� �� �����)
void Money::initMoney(int fh, int th, int h, int f, int t, int tn, int fi, int tw, int o, int fifty, int twentyFive, int ten, int five, int two, int one) {
    fiveHundred = fh;
    twoHundred = th;
    hundred = h;
    fifty = f;
    twenty = t;
    ten = tn;
    five = fi;
    two = tw;
    one = o;
    fiftyKop = fifty;
    twentyFiveKop = twentyFive;
    tenKop = ten;
    fiveKop = five;
    twoKop = two;
    oneKop = one;
}

// ������� �������� ���� ������
double Money::getTotalAmount() const {
    // ����� �������
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 }; // �������
    // ����� ������� ������� �������
    int counts[] = { fiveHundred, twoHundred, hundred, fifty, twenty, ten, five, two, one,
                    fiftyKop, twentyFiveKop, tenKop, fiveKop, twoKop, oneKop }; // ʳ������ �����/�����

    double totalAmount = 0.0;

    // ���������� �������� ����, ������� ������� ������� ������� �� ���� �������
    for (int i = 0; i < 15; i++) {
        totalAmount += denominations[i] * counts[i];
    }

    return totalAmount;
}

// ������������ ���� � ��������� ������
string Money::numberToWords(double amount) const {
    int integerPart = static_cast<int>(amount); // �������� ���� ������� ����
    int fractionalPart = static_cast<int>((amount - integerPart) * 100); // ���������� ������� ������� ��� ����������

    // ����� ����� ��� �������, ������� � ������
    const string ones[] = { "", "����", "���", "���", "������", "����", "�����", "��", "���", "������" };
    const string teens[] = { "������", "����������", "����������", "����������", "������������", "����������", "�����������", "���������", "����������", "������������" };
    const string tens[] = { "", "������", "��������", "��������", "�����", "��������", "���������", "�������", "��������", "���������" };
    const string hundreds[] = { "", "���", "����", "������", "���������", "������", "�������", "�����", "������", "��������" };

    string result = "";

    // ��������� ���� ������� (�����)
    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";  // ��� ����� 10-19
    else if (onesPart > 0) result += ones[onesPart] + " ";

    // ������ "�������"
    if (integerPart == 1) result += "������";
    else if (integerPart >= 2 && integerPart <= 4) result += "�����";
    else result += "�������";

    // ���� � ������, ������ ��
    if (fractionalPart > 0) {
        result += " , ";

        int kop = fractionalPart;

        // ��������� ������
        int kopTensPart = kop / 10;
        int kopOnesPart = kop % 10;

        if (kopTensPart > 1) result += tens[kopTensPart] + " ";
        if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
        else if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";

        // ������ "������"
        if (kop == 1) result += "������";
        else if (kop >= 2 && kop <= 4) result += "������";
        else result += "������";
    }

    return result;
}

// ��������� �������
void Money::displayBalance() const {
    cout << "������: " << getTotalAmount() << " ���\n";  // ��������� �������
}

// �������� ���������
void Money::addMoney(double amount) {
    // ����� ������� �� ��������� ������ ��� ������� ������
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 };
    int* counts[] = { &fiveHundred, &twoHundred, &hundred, &fifty, &twenty, &ten, &five,
                     &two, &one, &fiftyKop, &twentyFiveKop, &tenKop, &fiveKop, &twoKop, &oneKop };

    // ������ ��� ������� ��� ���������
    for (int i = 0; i < 15; i++) {
        // ���������� ������� �����/�����
        int needed = static_cast<int>(amount / denominations[i]);
        amount -= needed * denominations[i]; // �������� ����

        // ��������� �� �������� �������
        *counts[i] += needed;
    }

    // �������� ��������� ������
    displayBalance();
}

// �������� ������
bool Money::withdrawMoney(double amount) {
    // ����� �������
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 }; // �������
    // ����� ������� ������� �������
    int* counts[] = { &fiveHundred, &twoHundred, &hundred, &fifty, &twenty, &ten, &five,
                     &two, &one, &fiftyKop, &twentyFiveKop, &tenKop, &fiveKop, &twoKop, &oneKop };
    for (int i = 0; i < 15; i++) {
        // ��������� ������� �����/����� ��� ������
        int needed = static_cast<int>(amount / denominations[i]);

        // ����������, �� � ��������� �����/�����
        if (getTotalAmount() < needed) return false; // ���� ����������� �����

        amount -= needed * denominations[i]; // �������� ���� �� ����� �������
        *counts[i] -= needed; // �������� �������
    }

    // ��������� ������� ���� ������ ������
    displayBalance();
    return true;
}
