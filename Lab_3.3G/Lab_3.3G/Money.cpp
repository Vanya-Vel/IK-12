#include "Money.h"
#include <iostream>
#include <string>

using namespace std;

// ����������� �� �������������
Money::Money() : fiveHundred(0), twoHundred(0), hundred(0), fifty(0), twenty(0), ten(0), five(0), two(0), one(0),
fiftyKop(0), twentyFiveKop(0), tenKop(0), fiveKop(0), twoKop(0), oneKop(0) {}

// ����������� � �������������
Money::Money(const MoneyValues& values) {
    fiveHundred = values.fh;
    twoHundred = values.th;
    hundred = values.h;
    fifty = values.f;
    twenty = values.t;
    ten = values.tn;
    five = values.fi;
    two = values.tw;
    one = values.o;
    fiftyKop = values.fifty;
    twentyFiveKop = values.twentyFive;
    tenKop = values.ten;
    fiveKop = values.five;
    twoKop = values.two;
    oneKop = values.one;
}

// ����������� �����������
Money::Money(const Money& other) {
    fiveHundred = other.fiveHundred;
    twoHundred = other.twoHundred;
    hundred = other.hundred;
    fifty = other.fifty;
    twenty = other.twenty;
    ten = other.ten;
    five = other.five;
    two = other.two;
    one = other.one;
    fiftyKop = other.fiftyKop;
    twentyFiveKop = other.twentyFiveKop;
    tenKop = other.tenKop;
    fiveKop = other.fiveKop;
    twoKop = other.twoKop;
    oneKop = other.oneKop;
}

// ����� ��� ��������� �������� ����
double Money::getTotalAmount() const {
    double total = fiveHundred * 500 + twoHundred * 200 + hundred * 100 + fifty * 50 + twenty * 20 +
        ten * 10 + five * 5 + two * 2 + one * 1;
    total += (fiftyKop * 0.50) + (twentyFiveKop * 0.25) + (tenKop * 0.10) + (fiveKop * 0.05) +
        (twoKop * 0.02) + (oneKop * 0.01);
    return total;
}

// ����� ��� ������������ ���� � �����
string Money::numberToWords(double amount) const {
    int integerPart = static_cast<int>(amount); // �������� ���� ������� ����
    int fractionalPart = static_cast<int>((amount - integerPart) * 100); // ���������� ������� ������� ��� ����������

    // ����� ����� ��� �������, ������� � ������
    const string ones[] = { "", "����", "���", "���", "������", "����", "�����", "��", "���", "������" };
    const string teens[] = { "������", "����������", "����������", "����������", "������������", "����������", "�����������", "���������", "����������", "������������" };
    const string tens[] = { "", "������", "��������", "��������", "�����", "��������", "���������", "�������", "��������", "���������" };
    const string hundreds[] = { "", "���", "����", "������", "���������", "������", "�������", "�����", "������", "��������" };

    string result = "";

    // ��������� ���� ������� (������)
    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";  // ��� ����� 10-19
    else if (onesPart > 0) result += ones[onesPart] + " ";

    // ������ "�������"
    if (integerPart == 1) result += "������";
    else if (integerPart >= 2 && integerPart <= 4) result += "������";
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

// ����� ��� ��������� ������
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

// ����� ��� ������ ������
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

// ����� ��� ��������� �������
void Money::displayBalance() const {
    cout << "������: " << getTotalAmount() << " ���" << endl;
}

// �������������� ��������� ������
ostream& operator<<(ostream& os, const Money& money) {
    os << "������: " << money.getTotalAmount() << " ���";
    return os;
}

// �������������� ��������� �����
istream& operator>>(istream& is, Money& money) {
    Money::MoneyValues values;
    cout << "������ ������� 500 ���: ";
    is >> values.fh;
    cout << "������ ������� 200 ���: ";
    is >> values.th;
    cout << "������ ������� 100 ���: ";
    is >> values.h;
    cout << "������ ������� 50 ���: ";
    is >> values.f;
    cout << "������ ������� 20 ���: ";
    is >> values.t;
    cout << "������ ������� 10 ���: ";
    is >> values.tn;
    cout << "������ ������� 5 ���: ";
    is >> values.fi;
    cout << "������ ������� 2 ���: ";
    is >> values.tw;
    cout << "������ ������� 1 ���: ";
    is >> values.o;
    cout << "������ ������� 50 ������: ";
    is >> values.fifty;
    cout << "������ ������� 25 ������: ";
    is >> values.twentyFive;
    cout << "������ ������� 10 ������: ";
    is >> values.ten;
    cout << "������ ������� 5 ������: ";
    is >> values.five;
    cout << "������ ������� 2 ������: ";
    is >> values.two;
    cout << "������ ������� 1 ������: ";
    is >> values.one;

    money = Money(values);
    return is;
}

Money::~Money(void)
{}