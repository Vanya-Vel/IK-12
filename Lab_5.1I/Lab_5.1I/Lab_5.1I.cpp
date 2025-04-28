// Lab_05_1I.cpp
// < Величко Іван >
// Лабораторна робота № 5.1I
// Класи з опрацюванням виняткових ситуацій
// Варіант 0.4

#include <iostream>
#include "Functions.h"
#include "Money.h"
#include <windows.h>
#include <string>
#include "Object.h"

using namespace std;

void Exception()
{
    try {
        throw ErrorWithdrawal();
    }
    catch (ErrorWithdrawal e) {
        cout << "[by value] Exception: " << e.what() << endl;              // Виняток за значенням
    }

    try {
        throw ErrorWithdrawal();
    }
    catch (ErrorWithdrawal& e) {
        cout << "[by reference] Exception: " << e.what() << endl;          // Виняток за посиланням
    }

    try {
        throw new ErrorWithdrawal();
    }
    catch (ErrorWithdrawal* e) {
        cout << "[by pointer] Exception: " << e->what() << endl << endl;   // Виняток за вказівником
        delete e;
    }
}

int main() {
    // Встановлення кодування для кирилиці
    SetConsoleOutputCP(1251);  // Для виведення кирилиці в Windows

    // Введення даних для банкомату
    string atmID;
    double minAmount, maxAmount;

    Functions atm;

    try {
        cout << "Введіть ID банкомату: ";
        cin >> atmID;
        if (!atm.validateATMID(atmID)) {
            return 1;
        }

        cout << "Введіть мінімальну суму для зняття: ";
        cin >> minAmount;

        cout << "Введіть максимальну суму для зняття: ";
        cin >> maxAmount;
        if (minAmount < 0 || maxAmount > 5000 || minAmount >= maxAmount) {
            throw ErrorWithdrawal(); // Виняток, якщо ID некоректний
        }
        atm = Functions(atmID, minAmount, maxAmount);
        cout << "Банкомат ID: " << atmID << endl;
        atm.displayBalance(); // Вивести баланс банкомату

    }
    catch (ErrorWithdrawal& e) {
        Exception();
        return 1;
    }

    cout << "Count object = " << Object::Count() << endl << endl;

    // Меню внесення грошей
    double amount;
    int choice;
    double denominations[] = { 500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0,
                               0.5, 0.25, 0.1, 0.05, 0.02, 0.01 };

    while (true) {
        cout << "\nОберіть номінал для внесення грошей:\n";
        for (int i = 0; i < 15; i++) {
            cout << i + 1 << ". " << denominations[i] << (i < 8 ? " грн" : " копійок") << endl;
        }
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 0) {
            break;  // Вихід з циклу
        }

        if (choice < 1 || choice > 15) {
            cout << "Невірний вибір.\n";
            continue;
        }

        try {
            cout << "Введіть кількість: ";
            cin >> amount;

            if (amount <= 0) {
                throw new ErrorAmount(); // Виняток
            }
            atm.depositMoney(denominations[choice - 1] * amount);
            atm.displayBalance();  // Показуємо оновлений баланс
        }
        catch (ErrorAmount* e) {
            cout << "[за вказівником] Exception: " << e->what() << endl << endl;   // Виняток за вказівником
            delete e;
            return 1;
        }
    }

    // Виведення балансу в буквений формат
    cout << atm;  // Використовуємо перевантажений оператор виводу для балансу в словах

    // Зняття грошей
    double withdrawalAmount;

    cout << "\nВведіть суму для зняття: ";
    cin >> withdrawalAmount;

    if (atm.withdrawMoney(withdrawalAmount)) {
        cout << "Гроші успішно знято: " << withdrawalAmount << " грн\n";
    }
    else {
        cout << "Помилка: недостатньо коштів у банкоматі.\n";
    }
    // Виведення балансу після зняття
    atm.displayBalance();
    cout << atm;  // Баланс після зняття в букв. форматі

    cout << "Count object = " << Object::Count() << endl;

// Копіювання банкомату за допомогою копіювального конструктора
    Functions atmCopy = atm;  // Це викликає копіювальний конструктор
    cout << "\nКопія банкомату баланс:\n";
    atmCopy.displayBalance(); // Перевіримо баланс у копії

    cout << "Count object = " << Object::Count();
    return 0;
}
