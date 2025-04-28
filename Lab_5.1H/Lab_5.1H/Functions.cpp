#include "Functions.h"
#include <iostream>
#include <stdexcept>

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
    os << "Баланс в словах: " << functions.atmMoney.numberToWords(total) << endl;

    return os;
}