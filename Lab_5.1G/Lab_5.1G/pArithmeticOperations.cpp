#include "pArithmeticOperations.h"

// �������� ����������� ����������
pArithmeticOperations& pArithmeticOperations::operator++() {
    if (!Exception()) {
        // ���� Exception() ������� false, ���������� ���������
        cout << "Skipping increment due to invalid Pair state." << endl;
        return *this;  // ��������� ��� ���
    }
    // ��������� ������� �� ������� ��������
    setFirst(getFirst() + 1);
    setSecond(getSecond() + 1);
    return *this;
}

// �������� ������������ ����������
pArithmeticOperations pArithmeticOperations::operator++(int) {

    if (!Exception()) {
        pArithmeticOperations temp;
        // ���� Exception() ������� false, ���������� ���������
        cout << "Skipping increment due to invalid Pair state." << endl;
        return *this;  // ��������� ��� ���
    }
    pArithmeticOperations temp;
    // �������� �������� ��'���
    temp = *this;
    setFirst(getFirst() + 1);  // ��������� ������� ��������
    setSecond(getSecond() + 1); // ��������� ������� ��������
    return temp;  // ��������� ���������� ��'���
}

// �������� ����������� ����������
pArithmeticOperations& pArithmeticOperations::operator--() {
    if (!Exception()) {
        // ���� Exception() ������� false, ���������� ���������
        cout << "Skipping decrement due to invalid Pair state." << endl;
        return *this;  // ��������� ��� ���
    }
    // ��������� ������� �� ������� ��������
    setFirst(getFirst() - 1);
    setSecond(getSecond() - 1);
    return *this;
}

// �������� ������������ ����������
pArithmeticOperations pArithmeticOperations::operator--(int) {

    if (!Exception()) {
        // ���� Exception() ������� false, ���������� ���������
        cout << "Skipping decrement due to invalid Pair state." << endl;
        return *this;  // ��������� ��� ���
    }
    pArithmeticOperations temp;
    // �������� �������� ��'���
    temp = *this;
    setFirst(getFirst() - 1);  // ��������� ������� ��������
    setSecond(getSecond() - 1); // ��������� ������� ��������
    return temp;  // ��������� ���������� ��'���
}
