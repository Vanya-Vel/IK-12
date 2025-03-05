#pragma once
#include <iostream>
#include <string>
#include "Money.h"

using namespace std; // Додаємо простір імен std для скорочення запису

class Bankomat {
private:
    string atmID; // Змінна для зберігання ID банкомату
    Money atmMoney; // Об'єкт класу Money для управління грошима в банкоматі
    double minWithdrawalAmount; // Мінімальна сума для зняття
    double maxWithdrawalAmount; // Максимальна сума для зняття

public:
    // Конструктор за замовчуванням
    Bankomat();

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
