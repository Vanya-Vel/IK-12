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

// Перевірка правильності ID банкомату
bool Bankomat::validateATMID(string id) {
    try {
        if (id.length() != 1 || !isdigit(id[0])) {
            throw ErrorID();  // Кидаємо виняток при невірному ID
        }
    }
    catch (ErrorID e) {
        cout << "[за значенням] Exception: " << e.what() << endl;              // Виняток за значенням
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
