#pragma once  // ������ �� �������������� ��������� ������������� �����

class Money
{
private:
	unsigned int first;  // ������ ������
	unsigned int second; // ʳ������ �����

public:
	int GetFirst() const { return first; }  // �������� ������
	unsigned int GetSecond() const { return second; }  // �������� ������� �����

	void SetFirst(int value) { first = value; }  // ���������� ������
	void SetSecond(unsigned int value) { second = value; }  // ���������� ������� �����

	bool Init(int Denom, int NumOfDenom);  // ����������� ��'���� � ��������� ����������� ������� �����
	void Display() const;  // ���� ������� ������� � ������� ����� �� �����
	void Read();  // ���������� ������� � ���������

	int Summa() { return (first * second); } // ���������� �������� ���� ������
};
