#include "Functions.h"
#include <iostream>

using namespace std;

double Functions::distanceFromXtoY(const Functions& other) const {
    double dist = sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));

    double rounded = round(dist * 100) / 100;

    return rounded;
}

string Functions::toString(const Functions& other) const {
    try {
        double dist = distanceFromXtoY(other);
        return ToNumeral(dist);
    }
    catch (const PointException& ex) {
        return ex.what();  // ��������� ������� � ������� �������
    }
}

string Functions::ToNumeral(double amount) const {
    int integerPart = static_cast<int>(amount); // �������� ���� �������
    int fractionalPartInt = static_cast<int>(round((amount - integerPart) * 100)); // ���������� ������ �� 2 �����

    const string ones[] = { "", "����", "���", "���", "������", "����", "�����", "��", "���", "������" };
    const string teens[] = { "������", "����������", "����������", "����������", "������������", "����������", "�����������", "���������", "����������", "������������" };
    const string tens[] = { "", "������", "��������", "��������", "�����", "��������", "���������", "�������", "��������", "���������" };
    const string hundreds[] = { "", "���", "����", "������", "���������", "������", "�������", "�����", "������", "��������" };

    string result = "";

    // ������� ���� �������
    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";
    else if (onesPart > 0) result += ones[onesPart] + " ";

    if (integerPart == 1) result += "�������";
    else if (integerPart >= 2 && integerPart <= 4) result += "�������";
    else result += "�������";

    // ������� ������
    if (fractionalPartInt > 0) {
        result += " , ";

        if (fractionalPartInt % 10 == 0) {  // ���� ����� ������ 10 (10, 20, 30...)
            int dec = fractionalPartInt / 10;
            if (dec == 1) result += "���� ������";
            else if (dec == 2) result += "�� �����";
            else result += ones[dec] + " �������";
        }
        else {
            int kopTensPart = fractionalPartInt / 10;
            int kopOnesPart = fractionalPartInt % 10;

            if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
            else {
                if (kopTensPart > 1) result += tens[kopTensPart] + " ";
                if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";
            }

            if (fractionalPartInt == 1) result += "���� �����";
            else if (fractionalPartInt >= 2 && fractionalPartInt <= 4) result += "�����";
            else result += "�����";
        }
    }

    return result;
}