#pragma once
#include "AccessMethodology.h"
using namespace std;

// ���� ��� ������������ �������� � �������
class ArithmeticOperations : public AccessMethodology {
public:
    // ���������� ���������
    ArithmeticOperations& operator ++();     // ���������� ���������
    // ���������� ���������
    ArithmeticOperations& operator --();     // ���������� ���������
    // ����������� ���������
    ArithmeticOperations operator ++(int);   // ����������� ���������
    // ����������� ���������
    ArithmeticOperations operator --(int);   // ����������� ���������
    // �������� ���������
    ArithmeticOperations operator + (const ArithmeticOperations&);        // �������� ��������� �����
    // �������� ���������
    ArithmeticOperations& operator = (const ArithmeticOperations&);       // �������� ���������

    // �������� ��������, ��������� ��� ArithmeticOperations:
    // ����������� �� ����������
    ArithmeticOperations() : AccessMethodology() {}
    // ����������� � �����������
    ArithmeticOperations(int x, int y) : AccessMethodology(x, y) {}
    // ����������� ���������
    ArithmeticOperations(const ArithmeticOperations& other) : AccessMethodology(other) {}
};
