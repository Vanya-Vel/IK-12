#include "Bankomat.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // підключаємо бібліотеку, яка описує літерні потоки
using namespace std;

// class Bankomat

// Конструктор за замовчуванням
Bankomat::Bankomat() : minWithdrawalAmount(100), maxWithdrawalAmount(5000) {}

// Ініціалізація банкомату
void Bankomat::Init(string id, double minAmount, double maxAmount) {
    atmID = id;  // Присвоєння ідентифікатора банкомату
    minWithdrawalAmount = minAmount;  // Мінімальна сума для зняття
    maxWithdrawalAmount = maxAmount;  // Максимальна сума для зняття
}

// Перевірка правильності ID банкомату
bool Bankomat::validateATMID(string id) {
    return id.length() == 1;  // Перевірка, чи довжина ID дорівнює 1 (можна змінити умови за потребою)
}

// Виведення балансу
void Bankomat::displayBalance() {
    atmMoney.displayBalance();  // Викликаємо метод для виведення балансу банкомату
}

// Виведення балансу в букв. форматі
void Bankomat::displayBalanceInWords() {
    double totalAmount = atmMoney.getTotalAmount();  // Отримуємо загальну суму
    cout << "Баланс в букв. форматі: " << atmMoney.numberToWords(totalAmount) << endl;  // Виведення балансу словами
}

// Зняття грошей
bool Bankomat::withdrawMoney(double amount) {
    // Перевірка, чи сума знаходиться в межах лімітів
    if (amount >= minWithdrawalAmount && amount <= maxWithdrawalAmount) {
        // Якщо гроші зняти можна
        if (atmMoney.withdrawMoney(amount)) {
            cout << "Зняття коштів на суму: " << amount << " успішно.\n";
            cout << "Оновлений баланс:\n";
            atmMoney.displayBalance();  // Оновлений баланс після зняття
            return true;
        }
        else {
            cout << "Недостатньо грошей у банкоматі для цієї суми.\n";  // Якщо грошей недостатньо
            return false;
        }
    }
    else {
        cout << "Сума повинна бути між " << minWithdrawalAmount << " і " << maxWithdrawalAmount << " грн.\n";  // Якщо сума не в межах лімітів
        return false;
    }
}

// Внесення грошей
bool Bankomat::depositMoney(double amount) {
    atmMoney.addMoney(amount);  // Додаємо гроші до банкомату
    cout << "Внесено " << amount << " грн.\n";  // Повідомлення про внесену суму
    return true;
}

// Показ лімітів зняття
void Bankomat::showLimits() {
    cout << "Максимальна сума зняття: " << maxWithdrawalAmount << " грн\n";  // Виведення максимального ліміту зняття
    cout << "Мінімальна сума зняття: " << minWithdrawalAmount << " грн\n";  // Виведення мінімального ліміту зняття
}



// class Money

// Конструктор за замовчуванням
Bankomat::Money::Money() {
    // Ініціалізація всіх номіналів грошей в 0
    fiveHundred = twoHundred = hundred = fifty = twenty = ten = five = two = one = 0;
    fiftyKop = twentyFiveKop = tenKop = fiveKop = twoKop = oneKop = 0;
}

// Ініціалізація грошей (вказуємо конкретну кількість монет та купюр)
void Bankomat::Money::initMoney(int fh, int th, int h, int f, int t, int tn, int fi, int tw, int o, int fifty, int twentyFive, int ten, int five, int two, int one) {
    fiveHundred = fh;
    twoHundred = th;
    hundred = h;
    fifty = f;
    twenty = t;
    ten = tn;
    five = fi;
    two = tw;
    one = o;
    fiftyKop = fifty;
    twentyFiveKop = twentyFive;
    tenKop = ten;
    fiveKop = five;
    twoKop = two;
    oneKop = one;
}

// Повертає загальну суму грошей
double Bankomat::Money::getTotalAmount() const {
    // Масив номіналів
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 }; // Номінали
    // Масив кількості кожного номіналу
    int counts[] = { fiveHundred, twoHundred, hundred, fifty, twenty, ten, five, two, one,
                    fiftyKop, twentyFiveKop, tenKop, fiveKop, twoKop, oneKop }; // Кількість купюр/монет

    double totalAmount = 0.0;

    // Обчислюємо загальну суму, множачи кількість кожного номіналу на його вартість
    for (int i = 0; i < 15; i++) {
        totalAmount += denominations[i] * counts[i];
    }

    return totalAmount;
}

// Перетворення суми в текстовий формат
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

// Виведення балансу
void Bankomat::Money::displayBalance() const {
    cout << "Баланс: " << getTotalAmount() << " грн\n";  // Виведення балансу
}

// Операція додавання
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

// Операція зняття
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

