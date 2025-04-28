#include "Money.h"
#include <iostream>
#include <string>

using namespace std;

// Конструктор за замовчуванням
Money::Money() : fiveHundred(0), twoHundred(0), hundred(0), fifty(0), twenty(0), ten(0), five(0), two(0), one(0),
fiftyKop(0), twentyFiveKop(0), tenKop(0), fiveKop(0), twoKop(0), oneKop(0) {}

// Конструктор з ініціалізацією
Money::Money(const MoneyValues& values) {
    fiveHundred = values.fh;
    twoHundred = values.th;
    hundred = values.h;
    fifty = values.f;
    twenty = values.t;
    ten = values.tn;
    five = values.fi;
    two = values.tw;
    one = values.o;
    fiftyKop = values.fifty;
    twentyFiveKop = values.twentyFive;
    tenKop = values.ten;
    fiveKop = values.five;
    twoKop = values.two;
    oneKop = values.one;
}

// Копіювальний конструктор
Money::Money(const Money& other) {
    fiveHundred = other.fiveHundred;
    twoHundred = other.twoHundred;
    hundred = other.hundred;
    fifty = other.fifty;
    twenty = other.twenty;
    ten = other.ten;
    five = other.five;
    two = other.two;
    one = other.one;
    fiftyKop = other.fiftyKop;
    twentyFiveKop = other.twentyFiveKop;
    tenKop = other.tenKop;
    fiveKop = other.fiveKop;
    twoKop = other.twoKop;
    oneKop = other.oneKop;
}

// Метод для отримання загальної суми
double Money::getTotalAmount() const {
    double total = static_cast<double>(
        static_cast<long long>(fiveHundred) * 500 +
        static_cast<long long>(twoHundred) * 200 +
        static_cast<long long>(hundred) * 100 +
        static_cast<long long>(fifty) * 50 +
        static_cast<long long>(twenty) * 20 +
        static_cast<long long>(ten) * 10 +
        static_cast<long long>(five) * 5 +
        static_cast<long long>(two) * 2 +
        static_cast<long long>(one) * 1
        );
    total += (fiftyKop * 0.50) + (twentyFiveKop * 0.25) + (tenKop * 0.10) + (fiveKop * 0.05) +
        (twoKop * 0.02) + (oneKop * 0.01);
    return total;
}

// Метод для перетворення суми в текст
string Money::numberToWords(double amount) const {
    int integerPart = static_cast<int>(amount);
    int fractionalPart = static_cast<int>((amount - integerPart) * 100);

    const string ones[] = { "", "один", "два", "три", "чотири", "п’ять", "шість", "сім", "вісім", "дев’ять" };
    const string teens[] = { "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п’ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев’ятнадцять" };
    const string tens[] = { "", "десять", "двадцять", "тридцять", "сорок", "п’ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев’яносто" };
    const string hundreds[] = { "", "сто", "двісті", "триста", "чотириста", "п’ятсот", "шістсот", "сімсот", "вісімсот", "дев’ятсот" };

    string result = "";

    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";
    else if (onesPart > 0) result += ones[onesPart] + " ";

    if (integerPart == 1) result += "гривня";
    else if (integerPart >= 2 && integerPart <= 4) result += "гривні";
    else result += "гривень";

    if (fractionalPart > 0) {
        result += " , ";
        int kop = fractionalPart;
        int kopTensPart = kop / 10;
        int kopOnesPart = kop % 10;

        if (kopTensPart > 1) result += tens[kopTensPart] + " ";
        if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
        else if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";

        if (kop == 1) result += "копійка";
        else if (kop >= 2 && kop <= 4) result += "копійки";
        else result += "копійок";
    }

    return result;
}

// Метод для додавання грошей
void Money::addMoney(double amount) {
    if (amount <= 0) {
        throw ErrorAmount();  // Кидаємо власний виняток за значенням
    }

    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 };
    int* counts[] = { &fiveHundred, &twoHundred, &hundred, &fifty, &twenty, &ten, &five,
                     &two, &one, &fiftyKop, &twentyFiveKop, &tenKop, &fiveKop, &twoKop, &oneKop };

    for (int i = 0; i < 15; i++) {
        int needed = static_cast<int>(amount / denominations[i]);
        amount -= needed * denominations[i];
        *counts[i] += needed;
    }

    displayBalance();
}

// Метод для зняття грошей
bool Money::withdrawMoney(double amount) {
    // Масив номіналів
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 }; // Номінали
    // Масив кількості кожного номіналу
    int* counts[] = { &fiveHundred, &twoHundred, &hundred, &fifty, &twenty, &ten, &five,
                     &two, &one, &fiftyKop, &twentyFiveKop, &tenKop, &fiveKop, &twoKop, &oneKop };
    for (int i = 0; i < 15; i++) {
        // Визначаємо кількість монет/купюр для зняття
        int needed = static_cast<int>(amount / denominations[i]);

        // Перевіряємо, чи є достатньо монет/купюр
        if (getTotalAmount() < needed) return false; // Якщо недостатньо коштів

        amount -= needed * denominations[i]; // Зменшуємо суму на зняту кількість
        *counts[i] -= needed; // Зменшуємо кількість
    }

    // Оновлення балансу після зняття грошей
    displayBalance();
    return true;
}

// Метод для виведення балансу
void Money::displayBalance() const {
    cout << "Баланс: " << getTotalAmount() << " грн" << endl;
}

// Перевантаження оператора виводу
ostream& operator<<(ostream& os, const Money& money) {
    os << "Баланс: " << money.getTotalAmount() << " грн";
    return os;
}

// Перевантаження оператора вводу
istream& operator>>(istream& is, Money& money) {
    is >> money.fiveHundred >> money.twoHundred >> money.hundred >> money.fifty >>
        money.twenty >> money.ten >> money.five >> money.two >> money.one >>
        money.fiftyKop >> money.twentyFiveKop >> money.tenKop >> money.fiveKop >>
        money.twoKop >> money.oneKop;
    return is;
}
