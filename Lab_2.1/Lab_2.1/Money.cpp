#include "Money.h"
#include <iostream>
#include <sstream>

using namespace std;

Money::Money()		//���������� �� �������������
{
	first = 0;		// ���������� ������ �� 0
	second = 0;		// ���������� ������� ����� �� 0
}

Money::Money(unsigned int Denom, unsigned int NumOfDenom)	// ����������� � �����������
{
	// ����� �������� ���������� �������
	int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
	bool isValid = false;

	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)	// ���������� �� ���������� ������
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}
	// ���� ������ �� ����������, ������� �������� �� �������������
	if (!isValid)
	{
		first = 0;
		second = 0;
	}
	else
	{
		first = Denom;		// ������������ ������
		second = (NumOfDenom != 0) ? NumOfDenom : 0;	// �������� �� ������� ������� �����
	}
}

Money::Money(const Money& d)	// ����������� ���������
{
	first = d.first;			// ������� ������
	second = d.second;			// ������� ������� �����
}

Money::~Money()			// ����������
{ }

void Money::SetFirst(unsigned int Denom)		// ����� ��� ������������ �������
{
	// ����� � Init
	int validDenoms[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	bool isValid = false;


	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)	// �������� �� ����������� �������
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}
	// ���� ������ ����������, ������������ ��������, � ������ ������� ������������ 0
	if (isValid)
		first = Denom;
	else
		first = 0;
}

void Money::SetSecond(unsigned int NumOfDenom)		// ����� ��� ������������ ������� �����
{
	second = (NumOfDenom != 0) ? NumOfDenom : 0;	// ���� ������� ����� ����� �� 0, ������������ ��������
}

unsigned int Money::GetFirst() const				// ������ ��� �������
{
	return first;
}
		
unsigned int Money::GetSecond() const				// ������ ��� ������� �����
{
	return second;
}

Money& Money::operator = (const Money& d)			// �������� ���������
{
	if (this != &d) {		// �������� �� �������������
		first = d.first;
		second = d.second;
	}
	return *this;
}

Money::operator string () const		// ������������ � �����
{
	stringstream ss;
	ss << " First = " << first << endl;		// ������ �������� ����� ������� (������)
	ss << " Second = " << second << endl;	// ������ �������� ����� ������� (������� �����)
	return ss.str();
}

Money& Money::operator ++()		// ��������� ��������������� (�������� ������)
{
	first++;
	return *this;
}

Money& Money::operator --()		// ��������� ��������������� (�������� ������)
{
	first--;
	return *this;
}

Money Money::operator ++(int)	// ���������� ��������������� (��������� ����, ���� �������� ������� �����)
{
	Money t(*this);			// ������� �������� ��'���
	second++;				// �������� ������� �����
	return t;				// ��������� ���� �� ����
}

Money Money::operator --(int)	// ���������� ��������������� (��������� ����, ���� �������� ������� �����)
{
	Money t(*this);			// ������� �������� ��'���
	second--;				// �������� ������� �����
	return t;				// ��������� ���� �� ����
}

Money operator * (const Money& d, unsigned int multiplier) {	// �������� ��������
	return Money(d.first, d.second * multiplier);				// ��������� ����� ��'��� Money � ���������� ������� �����
}

ostream& operator << (ostream& out, const Money& d)				// �������� ���������
{
	// ����� � Display
	out << "first (denominations) = " << d.first << " second (number of denominations) = " << d.second << endl;
	out << "���� = " << d.first * d.second << endl;		// ���������� � �������� �������� ����
	return out;
}

istream& operator >> (istream& in, Money& d)		// �������� ��������
{
	// ����� � Read
	int Denom, NumOfDenom;
	int validDenoms[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	bool isValid = false;

	// �������� ������� �������� (�������)
	do {
		cout << "first = ";
		cin >> Denom;
		if (Denom <= 0)
		{
			cout << "�������! �������� �� ���� �������. ��������� �� ���.\n";
		}
		for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)
		{

			if (Denom == validDenoms[i])
			{
				isValid = true;
				break;
			}
						
		}
		if (!isValid && Denom > 0) {
			cout << "�������! ����������� �������� �������. ��������� �� ���.\n";
			break;
		}
		
	} while (!isValid);

	d.first = Denom;

	// �������� ������� �������� (������� �����)
	do {
		cout << "second = ";
		cin >> NumOfDenom;
		if (NumOfDenom <= 0) 
		{
			cout << "�������! �������� �� ���� �������. ��������� �� ���.\n";
		}
	} while (NumOfDenom <= 0);

	d.second = NumOfDenom;
	return in;
}