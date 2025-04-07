#include "Bankomat.h"
#include <iostream>
#include <string>

using namespace std;

Bankomat::Bankomat() : atmID("DefaultID"), minWithdrawalAmount(50), maxWithdrawalAmount(5000) {}

Bankomat::Bankomat(string id, double minAmount, double maxAmount) : atmID(id), minWithdrawalAmount(minAmount), maxWithdrawalAmount(maxAmount) {}

Bankomat::Bankomat(const Bankomat& other) {
    atmID = other.atmID;
    atmMoney = other.atmMoney;
    minWithdrawalAmount = other.minWithdrawalAmount;
    maxWithdrawalAmount = other.maxWithdrawalAmount;
}

// Перевірка правильності ID банкомату
bool Bankomat::validateATMID(string id) {
    return id.length() == 1;  // Перевірка довжини ID
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
            cout << "Гроші успішно знято: " << amount << " грн" << endl;
            return true;
        }
        else {
            cout << "Недостатньо коштів" << endl;
            return false;
        }
    }
    return false;
}

bool Bankomat::depositMoney(double amount) {
    atmMoney.addMoney(amount);
    cout << "Гроші успішно зараховано: " << amount << " грн" << endl;
    return true;
}

void Bankomat::showLimits() {
    cout << "Мінімальна сума для зняття: " << minWithdrawalAmount << " грн" << endl;
    cout << "Максимальна сума для зняття: " << maxWithdrawalAmount << " грн" << endl;
}

// Перевантаження оператора виводу
ostream& operator<<(ostream& os, const Bankomat& atm) {
    os << "Банкомат ID: " << atm.atmID << "\n";
    atm.displayBalance();
    return os;
}

// Перевантаження оператора вводу
istream& operator>>(istream& is, Bankomat& atm) {
    cout << "Введіть ID банкомату: ";
    is >> atm.atmID;
    cout << "Введіть мінімальну суму для зняття: ";
    is >> atm.minWithdrawalAmount;
    cout << "Введіть максимальну суму для зняття: ";
    is >> atm.maxWithdrawalAmount;

    return is;
}
