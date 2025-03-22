#include "Money.h"
#include <iostream>
using namespace std;

Money::Money() {
    size = 3;        // ����� ������ (3 ��������)
    count = 2;       // ��� �������� ��� ������ (������� �� �����)

    if (size > MAX_SIZE) {
        cout << "�������: ����� �������� MAX_SIZE!" << std::endl;
        size = MAX_SIZE;
    }

    // ����������� ��� �������� ������ ��������� 0
    for (size_t i = 0; i < size; i++) {
        summa[i] = 0;  // 0 ��� ����� �����
    }
}

Money::Money(size_t S, size_t v)
{   // (�����, ����� �������� ��� ��������)
    size = S;        // ����� ������ (3 ��������)

    if (size > MAX_SIZE) {
        cout << "�������: ����� �������� MAX_SIZE!" << std::endl;
        size = MAX_SIZE;
    }

    // ����������� ��� �������� ������
    for (size_t i = 0; i < size; i++) {
        summa[i] = v;
    }
}

Money::Money(const Money& other) {
    size = other.size;
    count = other.count;

    for (size_t i = 0; i < other.size; i++) {
        summa[i] = other.summa[i];
    }
}

Money Money::operator = (const Money& other)
{
    if (this != &other) {  // �������� �� �������������
        size = other.size;
        count = other.count;

        for (size_t i = 0; i < size; i++) {
            summa[i] = other.summa[i];
        }
    }
    return *this;
}

string Money::toString() const {

    int integerPart = 0;
    int fractionalPartInt = 0;
    
    for (size_t i = 0; i < 2; i++) {
        fractionalPartInt += summa[i] * pow(10, i);  // �������� ����� � �����
    }
    for (size_t i = 2; i < size; i++) {
        integerPart += summa[i] * pow(10, i - 2);  // �������� ����� � �����
    }

    const string ones[] = { "����", "����", "���", "���", "������", "����", "�����", "��", "���", "������" };
    const string teens[] = { "������", "����������", "����������", "����������", "������������", "����������", "�����������", "���������", "����������", "������������" };
    const string tens[] = { "", "������", "��������", "��������", "�����", "��������", "���������", "�������", "��������", "���������" };
    const string hundreds[] = { "", "���", "����", "������", "���������", "������", "�������", "�����", "������", "��������" };

    string result = "";

    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (onesPart == 0) result += ones[0] + " ";
    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";
    else if (onesPart > 0) result += ones[onesPart] + " ";

    if (integerPart == 1) result += "������";
    else if (integerPart == 2  || integerPart == 3 || integerPart == 4) result += "�����";
    else result += "�������";

    if (fractionalPartInt > 0) {
        result += " , ";
        int kopTensPart = fractionalPartInt / 10;
        int kopOnesPart = fractionalPartInt % 10;

        if (kopTensPart == 0) result += ones[0] + " ";
        if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
        else {
            if (kopTensPart > 1) result += tens[kopTensPart] + " ";
            if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";
        }

        if (fractionalPartInt == 1) result += "���� ����";
        else if (fractionalPartInt == 2 || fractionalPartInt == 3 || fractionalPartInt == 4) result += "���";
        else result += "�����";
    }

    return result;
}

istream& operator >> (istream& in, Money& other) {
    cout << "������ ����� ������: ";
    in >> other.size;

    if (other.size > other.MAX_SIZE) {
        cout << "�������: ����� �������� MAX_SIZE! ����������� ����������� " << other.MAX_SIZE << endl;
        other.size = other.MAX_SIZE;
    }

    cout << "������ " << other.size;
    if (other.size == 1)
    {
        cout << " ��������: ";
    }
    else if (other.size >= 2 && other.size <= 4)
    {
        cout << " ��������: ";
    }
    else cout << " �������: ";

    other.count = other.size;  // ������������ count �������� �� size

    for (size_t i = 0; i < other.size; i++) {  // ���� �� ��� �� size, � �� count
        in >> other.summa[i];
    }

    return in;
}

ostream& operator << (ostream& out, const Money& other) {
    out << "����� ������� (" << other.size << "): ";
    for (size_t i = 0; i < other.size; i++) {  // ��������� ��� ��������
        out << other.summa[i] << " ";
    }
    return out;
}
