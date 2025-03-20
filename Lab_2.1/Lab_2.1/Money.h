#pragma once  // ������ �� �������������� ��������� ������������� �����

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Money
{
private:
    unsigned int first;  // ������ ������
    unsigned int second; // ʳ������ �����

public:
    Money();                                 // ����������� ��� ���������
    Money(unsigned int, unsigned int);       // ����������� �����������
    Money(const Money&);                     // ����������� ���������
    ~Money();

    void SetFirst(unsigned int);             // ���������� ������
    void SetSecond(unsigned int);            // ���������� ������� �����
    unsigned int GetFirst() const { return first; }          // �������� ������
    unsigned int GetSecond() const { return second; }          // �������� ������� �����

    Money& operator = (const Money&);        // ���������
    operator string() const;                 // ���������� �� �����

    Money& operator ++();                    // ���������� ���������
    Money& operator --();                    // ���������� ���������
    Money operator ++(int);                  // ����������� ���������
    Money operator --(int);                  // ����������� ���������

    friend Money operator * (const Money&, unsigned int);  // ���������� �������� ���� ������

    friend ostream& operator << (ostream&, const Money&);    // ���������
    friend istream& operator >> (istream&, Money&);           // ��������
};

