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

// Конструктор за замовчуванням
Bankomat::Money::Money() : fiveHundred(0), twoHundred(0), hundred(0), fifty(0), twenty(0), ten(0), five(0), two(0), one(0),
fiftyKop(0), twentyFiveKop(0), tenKop(0), fiveKop(0), twoKop(0), oneKop(0) {}

// Конструктор з ініціалізацією
Bankomat::Money::Money(const MoneyValues& values) {
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
Bankomat::Money::Money(const Bankomat::Money& other) {
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
double Bankomat::Money::getTotalAmount() const {
    double total = fiveHundred * 500 + twoHundred * 200 + hundred * 100 + fifty * 50 + twenty * 20 +
        ten * 10 + five * 5 + two * 2 + one * 1;
    total += (fiftyKop * 0.50) + (twentyFiveKop * 0.25) + (tenKop * 0.10) + (fiveKop * 0.05) +
        (twoKop * 0.02) + (oneKop * 0.01);
    return total;
}

// Метод для перетворення суми в текст
string Bankomat::Money::numberToWords(double amount) const {
    int integerPart = static_cast<int>(amount); // Отримуємо цілу частину суми
    int fractionalPart = static_cast<int>((amount - integerPart) * 100); // Обчислюємо дробову частину без округлення

    // Масив чисел для одиниць, десятків і сотень
    const string ones[] = { "", "один", "два", "три", "чотири", "п’ять", "шість", "сім", "вісім", "дев’ять" };
    const string teens[] = { "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п’ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев’ятнадцять" };
    const string tens[] = { "", "десять", "двадцять", "тридцять", "сорок", "п’ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев’яносто" };
    const string hundreds[] = { "", "сто", "двісті", "триста", "чотириста", "п’ятсот", "шістсот", "сімсот", "вісімсот", "дев’ятсот" };

    string result = "";

    // Розбираємо цілу частину (гривні)
    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";  // Для чисел 10-19
    else if (onesPart > 0) result += ones[onesPart] + " ";

    // Додаємо "гривень"
    if (integerPart == 1) result += "гривня";
    else if (integerPart >= 2 && integerPart <= 4) result += "гривні";
    else result += "гривень";

    // Якщо є копійки, додаємо їх
    if (fractionalPart > 0) {
        result += " , ";

        int kop = fractionalPart;

        // Розбираємо копійки
        int kopTensPart = kop / 10;
        int kopOnesPart = kop % 10;

        if (kopTensPart > 1) result += tens[kopTensPart] + " ";
        if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
        else if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";

        // Додаємо "копійок"
        if (kop == 1) result += "копійка";
        else if (kop >= 2 && kop <= 4) result += "копійки";
        else result += "копійок";
    }

    return result;
}

// Метод для додавання грошей
void Bankomat::Money::addMoney(double amount) {
    // Масив номіналів та відповідних змінних для кількості грошей
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 };
    int* counts[] = { &fiveHundred, &twoHundred, &hundred, &fifty, &twenty, &ten, &five,
                     &two, &one, &fiftyKop, &twentyFiveKop, &tenKop, &fiveKop, &twoKop, &oneKop };

    // Перебір всіх номіналів для додавання
    for (int i = 0; i < 15; i++) {
        // Обчислення кількості купюр/монет
        int needed = static_cast<int>(amount / denominations[i]);
        amount -= needed * denominations[i]; // Зменшуємо суму

        // Додавання до відповідної кількості
        *counts[i] += needed;
    }

    // Показуємо оновлений баланс
    displayBalance();
}

// Метод для зняття грошей
bool Bankomat::Money::withdrawMoney(double amount) {
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
void Bankomat::Money::displayBalance() const {
    cout << "Баланс: " << getTotalAmount() << " грн" << endl;
}

// Перевантаження оператора виводу
ostream& operator<<(ostream& os, const Bankomat::Money& money) {
    os << "Баланс: " << money.getTotalAmount() << " грн";
    return os;
}

// Перевантаження оператора вводу
istream& operator>>(istream& is, Bankomat::Money& money) {
    Bankomat::Money::MoneyValues values;
    cout << "Введіть кількість 500 грн: ";
    is >> values.fh;
    cout << "Введіть кількість 200 грн: ";
    is >> values.th;
    cout << "Введіть кількість 100 грн: ";
    is >> values.h;
    cout << "Введіть кількість 50 грн: ";
    is >> values.f;
    cout << "Введіть кількість 20 грн: ";
    is >> values.t;
    cout << "Введіть кількість 10 грн: ";
    is >> values.tn;
    cout << "Введіть кількість 5 грн: ";
    is >> values.fi;
    cout << "Введіть кількість 2 грн: ";
    is >> values.tw;
    cout << "Введіть кількість 1 грн: ";
    is >> values.o;
    cout << "Введіть кількість 50 копійок: ";
    is >> values.fifty;
    cout << "Введіть кількість 25 копійок: ";
    is >> values.twentyFive;
    cout << "Введіть кількість 10 копійок: ";
    is >> values.ten;
    cout << "Введіть кількість 5 копійок: ";
    is >> values.five;
    cout << "Введіть кількість 2 копійок: ";
    is >> values.two;
    cout << "Введіть кількість 1 копійки: ";
    is >> values.one;

    money = Bankomat::Money(values);
    return is;
}
