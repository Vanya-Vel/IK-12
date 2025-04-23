#include "Money.h"
#include <iostream>
#include <sstream>
#include <stdexcept> // Для обробки винятку std::bad_exception

using namespace std;

Money::Money() {
    first = 0;
    second = 0;
}

Money::Money(unsigned int Denom, unsigned int NumOfDenom) {
    int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
    bool isValid = false;

    for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++) {
        if (Denom == validDenoms[i]) {
            isValid = true;
            break;
        }
    }

    if (!isValid) {
        first = 0;
        second = 0;
        throw InvalidDenominationException(); // Кидаємо власний виняток при неправильному номіналі
    }
    else {
        first = Denom;
        second = (NumOfDenom != 0) ? NumOfDenom : 0;
    }
}

Money::Money(const Money& d) {
    first = d.first;
    second = d.second;
}

Money::~Money() {}

void Money::SetFirst(unsigned int Denom) noexcept(false) {
    int validDenoms[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
    bool isValid = false;

    for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++) {
        if (Denom == validDenoms[i]) {
            isValid = true;
            break;
        }
    }

    if (!isValid) {
        throw InvalidDenominationException();  // Кидаємо виняток для невірного номіналу
    }
    first = Denom;
}

void Money::SetSecond(unsigned int NumOfDenom) {
    if (NumOfDenom <= 0) {
        throw bad_exception();  // Стандартний виняток bad_exception
    }
    second = NumOfDenom;
}

Money& Money::operator = (const Money& d) {
    if (this != &d) {
        first = d.first;
        second = d.second;
    }
    return *this;
}

Money::operator string() const {
    stringstream ss;
    ss << " First = " << first << endl;
    ss << " Second = " << second << endl;
    return ss.str();
}

Money& Money::operator ++() {
    first++;
    return *this;
}

Money& Money::operator --() {
    first--;
    return *this;
}

Money Money::operator ++(int) {
    Money t(*this);
    second++;
    return t;
}

Money Money::operator --(int) {
    Money t(*this);
    second--;
    return t;
}

Money operator * (const Money& d, unsigned int multiplier) {
    return Money(d.first, d.second * multiplier);
}

ostream& operator << (ostream& out, const Money& d) {
    out << "first (denominations) = " << d.first << " second (number of denominations) = " << d.second << endl;
    out << "Сума = " << d.first * d.second << endl;
    return out;
}

istream& operator >> (istream& in, Money& d) {
    int Denom, NumOfDenom;
    int validDenoms[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
    bool isValid = false;

    do {
        cout << "first = ";
        cin >> Denom;
        if (Denom <= 0) {
            cout << "Помилка! Значення має бути додатнім. Спробуйте ще раз.\n";
        }
        for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++) {
            if (Denom == validDenoms[i]) {
                isValid = true;
                break;
            }
        }
        do {
            cout << "first = ";
            cin >> Denom;
            if (!isValid && Denom > 0) {
                cout << "Помилка! Неправильне значення номіналу. Спробуйте ще раз.\n";
            }
        } while (!isValid && Denom > 0);

    } while (!isValid);

    d.first = Denom;

    do {
        cout << "second = ";
        cin >> NumOfDenom;
        if (NumOfDenom <= 0) {
            cout << "Помилка! Значення має бути додатнім. Спробуйте ще раз.\n";
        }
    } while (NumOfDenom <= 0);

    d.second = NumOfDenom;
    return in;
}
