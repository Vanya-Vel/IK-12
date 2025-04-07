#include "Functions.h"
#include <iostream>

using namespace std;

// Перевантаження оператора виводу для банкомату та балансу в словах
ostream& operator<<(ostream& os, const Functions& functions) {
    // Виведення інформації про банкомат
    cout << endl;
    os << "Банкомат ID: " << functions.atmID << "\n";
    os << "Мінімальна сума для зняття: " << functions.minWithdrawalAmount << "\n";
    os << "Максимальна сума для зняття: " << functions.maxWithdrawalAmount << "\n";

    // Виведення балансу в словах
    double total = functions.atmMoney.getTotalAmount();
    os << "Баланс в словах: " << functions.atmMoney.numberToWords(total)<< endl;

    return os;
}

// Перевантаження оператора вводу для банкомату
istream& operator>>(istream& is, Functions& functions) {
    // Вводимо дані для банкомату
    cout << "Введіть ID банкомату: ";
    is >> functions.atmID;
    cout << "Введіть мінімальну суму для зняття: ";
    is >> functions.minWithdrawalAmount;
    cout << "Введіть максимальну суму для зняття: ";
    is >> functions.maxWithdrawalAmount;

    return is;
}
