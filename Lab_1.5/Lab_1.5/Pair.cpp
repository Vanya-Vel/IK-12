#include "Pair.h"
#include <iostream>
using namespace std;

void Pair::Init(int first, int second)
{
	setFirst(first);  // ������������ ������� �������� ����
	setSecond(second);  // ������������ ������� �������� ����
}

void Pair::Display() const
{
	cout << endl;
	cout << "First number = " << first << endl;  // ��������� ������� ��������
	cout << "Second number = " << second << endl;  // ��������� ������� ��������
}

void Pair::Read()
{
	int first, second;
	cout << endl;
	cout << "First = ? "; cin >> first;  // �������� ������� ��������
	cout << "Second = ? "; cin >> second;  // �������� ������� ��������
	Init(first, second);  // ����������� ���� ��������� ����������
}
