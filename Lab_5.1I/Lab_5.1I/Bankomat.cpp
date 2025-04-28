#include "Bankomat.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Bankomat::Bankomat() : atmID("DefaultID"), minWithdrawalAmount(0), maxWithdrawalAmount(0) {}

Bankomat::Bankomat(string id, double minAmount, double maxAmount) : atmID(id), minWithdrawalAmount(minAmount), maxWithdrawalAmount(maxAmount) {}

Bankomat::Bankomat(const Bankomat& other) {
    atmID = other.atmID;
    atmMoney = other.atmMoney;
    minWithdrawalAmount = other.minWithdrawalAmount;
    maxWithdrawalAmount = other.maxWithdrawalAmount;
}

// �������� ����������� ID ���������
bool Bankomat::validateATMID(string id) {
    try {
        if (id.length() != 1 || !isdigit(id[0])) {
            throw ErrorID();  // ������ ������� ��� �������� ID
        }
    }
    catch (ErrorID e) {
        cout << "[�� ���������] Exception: " << e.what() << endl;              // ������� �� ���������
        return false;
    }
    return true;
}

void Bankomat::displayBalance() const {
    cout << atmMoney << endl;
}

void Bankomat::displayBalanceInWords() {
    double total = atmMoney.getTotalAmount();
    cout << atmMoney.numberToWords(total) << endl;
}

bool Bankomat::withdrawMoney(double amount) {
    if (amount >= minWithdrawalAmount && amount <= maxWithdrawalAmount) {
        if (atmMoney.withdrawMoney(amount)) {
            cout << "����� ������ �����: " << amount << " ���" << endl;
            return true;
        }
        else {
            cout << "����������� �����" << endl;
            return false;
        }
    }
    return false;
}

bool Bankomat::depositMoney(double amount) {
    atmMoney.addMoney(amount);
    cout << "����� ������ ����������: " << amount << " ���" << endl;
    return true;
}

void Bankomat::showLimits() {
    cout << "̳������� ���� ��� ������: " << minWithdrawalAmount << " ���" << endl;
    cout << "����������� ���� ��� ������: " << maxWithdrawalAmount << " ���" << endl;
}

// �������������� ��������� ������
ostream& operator<<(ostream& os, const Bankomat& atm) {
    os << "�������� ID: " << atm.atmID << "\n";
    atm.displayBalance();
    return os;
}
