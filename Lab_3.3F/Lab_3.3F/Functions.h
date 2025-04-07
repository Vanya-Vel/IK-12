#pragma once
#include <string>
#include "Bankomat.h"

using namespace std;

class Functions : public Bankomat {
public:
    // Перевантаження оператора виводу для банкомату
    friend ostream& operator<<(ostream& os, const Functions& functions);

    // Перевантаження оператора вводу для банкомату
    friend istream& operator>>(istream& is, Functions& functions);

    // Перевантаження оператора виводу для балансу в словах
    friend ostream& operator<<(ostream& os, const Functions& functions);

    Functions() : Bankomat() {}
    Functions(string id, double minAmount, double maxAmount) : Bankomat(id, minAmount, maxAmount) {}
    Functions(const Bankomat& other) : Bankomat(other) {}
};
