#pragma once
using namespace std; // Додаємо простір імен std для скорочення запису
#include <string>

class Bankomat
{
public:
    // Оголошення внутрішнього класу Money
    class Money {
    private:
        // Змінні для кількості кожного номіналу (гривні та копійки)
        int fiveHundred, twoHundred, hundred, fifty, twenty, ten, five, two, one;
        int fiftyKop, twentyFiveKop, tenKop, fiveKop, twoKop, oneKop;

    public:
        // Конструктор за замовчуванням
        Money();

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

private:
    string atmID; // Змінна для зберігання ID банкомату
    Money atmMoney; // Об'єкт класу Money для управління грошима в банкоматі
    double minWithdrawalAmount; // Мінімальна сума для зняття
    double maxWithdrawalAmount; // Максимальна сума для зняття

public:
    // Конструктор за замовчуванням
    Bankomat();

    // Геттер для мінімальної суми
    double getMinWithdrawalAmount() const {
        return minWithdrawalAmount;
    }

    // Геттер для максимальної суми
    double getMaxWithdrawalAmount() const {
        return maxWithdrawalAmount;
    }

    // Ініціалізація банкомату
    void Init(string id, double minAmount, double maxAmount);

    // Перевірка правильності ID банкомату
    bool validateATMID(string id);

    // Виведення балансу
    void displayBalance();

    // Виведення балансу в букв. форматі
    void displayBalanceInWords();

    // Зняття грошей
    bool withdrawMoney(double amount);

    // Внесення грошей
    bool depositMoney(double amount);

    // Показ лімітів зняття
    void showLimits();
};
