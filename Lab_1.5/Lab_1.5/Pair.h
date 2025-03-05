#pragma once

#include <string>
using namespace std;

class Pair
{
private:
	int first, second;  // ��� �������� ����

public:
	// ��������� ������� �������� ����
	int getFirst() const { return first; }

	// ������������ ������� �������� ����
	void setFirst(int first) { this->first = first; }

	// ��������� ������� �������� ����
	int getSecond() const { return second; }

	// ������������ ������� �������� ����
	void setSecond(int second) { this->second = second; }

	// ���������� ������� ���� �������� ����
	int multiply() const { return first * second; }

	// ����������� ���� ����������
	void Init(int first, int second);

	// ��������� ������� ����
	void Display() const;

	// ������� ������� ����
	void Read();
};
