#pragma once
#include <string>
#include <iostream>

using namespace std; // Додаємо простір імен std для скорочення запису

class Money {
private:
    // Змінні для кількості кожного номіналу (гривні та копійки)
    int fiveHundred, twoHundred, hundred, fifty, twenty, ten, five, two, one;
    int fiftyKop, twentyFiveKop, tenKop, fiveKop, twoKop, oneKop;

public:
    // Конструктор за замовчуванням
    Money() {
        // Ініціалізація всіх номіналів грошей в 0
        fiveHundred = twoHundred = hundred = fifty = twenty = ten = five = two = one = 0;
        fiftyKop = twentyFiveKop = tenKop = fiveKop = twoKop = oneKop = 0;
    }

    // Ініціалізація грошей (вказуємо конкретну кількість монет та купюр)
    void initMoney(int fh, int th, int h, int f, int t, int tn, int fi, int tw, int o, int fifty, int twentyFive, int ten, int five, int two, int one);

    // Повертає суму в гривнях (гривні та копійки)
    double getTotalAmount() const;

    // Перетворення суми в текстовий формат (гривні та копійки)
    string numberToWords(double amount) const;

    // Виведення балансу (гривні та копійки)
    void displayBalance() const;

    // Операція додавання грошей (додаємо певну суму)
    void addMoney(double amount);

    // Операція зняття грошей (знімаємо певну суму)
    bool withdrawMoney(double amount);
};
