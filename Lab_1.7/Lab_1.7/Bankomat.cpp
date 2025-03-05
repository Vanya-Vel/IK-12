#include "Bankomat.h"

using namespace std; // ������ ������ ���� std ��� ���������� ������

// ����������� �� �������������
Bankomat::Bankomat() : minWithdrawalAmount(100), maxWithdrawalAmount(5000) {}

// ����������� ���������
void Bankomat::Init(string id, double minAmount, double maxAmount) {
    atmID = id;  // ��������� �������������� ���������
    minWithdrawalAmount = minAmount;  // ̳������� ���� ��� ������
    maxWithdrawalAmount = maxAmount;  // ����������� ���� ��� ������
}

// �������� ����������� ID ���������
bool Bankomat::validateATMID(string id) {
    return id.length() == 1;  // ��������, �� ������� ID ������� 1 (����� ������ ����� �� ��������)
}

// ��������� �������
void Bankomat::displayBalance() {
    atmMoney.displayBalance();  // ��������� ����� ��� ��������� ������� ���������
}

// ��������� ������� � ����. ������
void Bankomat::displayBalanceInWords() {
    double totalAmount = atmMoney.getTotalAmount();  // �������� �������� ����
    cout << "������ � ����. ������: " << atmMoney.numberToWords(totalAmount) << endl;  // ��������� ������� �������
}

// ������ ������
bool Bankomat::withdrawMoney(double amount) {
    // ��������, �� ���� ����������� � ����� ����
    if (amount >= minWithdrawalAmount && amount <= maxWithdrawalAmount) {
        // ���� ����� ����� �����
        if (atmMoney.withdrawMoney(amount)) {
            cout << "������ ����� �� ����: " << amount << " ������.\n";
            cout << "��������� ������:\n";
            atmMoney.displayBalance();  // ��������� ������ ���� ������
            return true;
        }
        else {
            cout << "����������� ������ � �������� ��� ���� ����.\n";  // ���� ������ �����������
            return false;
        }
    }
    else {
        cout << "���� ������� ���� �� " << minWithdrawalAmount << " � " << maxWithdrawalAmount << " ���.\n";  // ���� ���� �� � ����� ����
        return false;
    }
}

// �������� ������
bool Bankomat::depositMoney(double amount) {
    atmMoney.addMoney(amount);  // ������ ����� �� ���������
    cout << "������� " << amount << " ���.\n";  // ����������� ��� ������� ����
    return true;
}

// ����� ���� ������
void Bankomat::showLimits() {
    cout << "����������� ���� ������: " << maxWithdrawalAmount << " ���\n";  // ��������� ������������� ���� ������
    cout << "̳������� ���� ������: " << minWithdrawalAmount << " ���\n";  // ��������� ���������� ���� ������
}
