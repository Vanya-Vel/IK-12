#include "Money.h"
#include <iostream>
using namespace std;

// �������� ���������� ������� �� ������� �����
bool Money::Init(int Denom, int NumOfDenom)
{
	int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };

	// �������� �� Denom � � ������ ���������� �������
	bool isValid = false;
	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}

	// ���� ������ ������������, ������� ��������
	if (!isValid)
	{
		first = 0;
		return false;
	}
	else first = Denom;

	// ��������, �� ������� ����� �� ������� ����
	if (NumOfDenom != 0)
	{
		second = NumOfDenom;
		return true;
	}
	else
	{
		second = 0;
		return false;
	}
}

// ���� ������� �� ������� �����
void Money::Display() const
{
	cout << "first (denominations) = " << first << " second (number of denominations) = " << second << endl;
}

// ���������� ����� � ���������
void Money::Read()
{
	int Denom, NumOfDenom;

	// ������� ������ ���� �� �� ����� ����������
	do {
		cout << "first = ";
		cin >> Denom;
	} while (!Init(Denom, 1));

	// ������� ������� ����� ���� ���� �� ���� ����������
	do {
		cout << "second = ";
		cin >> NumOfDenom;
	} while (!Init(Denom, NumOfDenom));
}
