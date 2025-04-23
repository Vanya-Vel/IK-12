// Lab_05_1A.cpp
// < Величко Іван >
// Лабораторна робота № 5.1A
// Класи з опрацюванням виняткових ситуацій
// Варіант 0.4

#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "Money.h"

using namespace std;

// Власний виняток
class MoneyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Помилка класу Money: Некоректне значення!";
    }
};

// Функція для створення Money з введенням з клавіатури
Money createMoneyFromInput() {
    unsigned int nom, kt;
    cout << "\nВведіть номінал (грн): ";
    cin >> nom;
    cout << "Введіть кількість (к-ть): ";
    cin >> kt;

    // Перевірка діапазону
    if (kt <= 0) throw std::invalid_argument("Кількість має бути більше 0!");
    if (nom == 0 && kt == 0) throw MoneyException(); // власний виняток

    return Money(nom, kt);
}

int main() {

    // Встановлення кодування для кирилиці у Windows
    SetConsoleOutputCP(1251);

    try {
        // Введення з клавіатури
        Money money1, money2;
        try {
            cout << "Створення money1:";
            money1 = createMoneyFromInput();
            cout << "money1: " << money1 << endl;

            cout << "\nСтворення money2:";
            money2 = createMoneyFromInput();
            cout << "money2: " << money2 << endl;
        }
        catch (const std::invalid_argument& e) {
            cout << "[std::invalid_argument] Некоректна кількість: " << e.what() << endl;
            return 1;
        }
        catch (const MoneyException& e) {
            cout << "[MoneyException] Власний виняток: " << e.what() << endl;
            return 1;
        }

        // Перевірка та виняток-нащадок
        try {
            if (money1.GetFirst() == 999)
                throw std::logic_error("Недопустимий номінал (999 грн)!");
        }
        catch (const std::logic_error& e) {
            cout << "[logic_error] Виняток-нащадок: " << e.what() << endl;
        }

        // Операції з грошима
        try {

            Money mult = money1 * 2;
            cout << "Множення: " << mult << endl;
        }
        catch (const exception& e) {
            cout << "[std::exception] Помилка при операціях: " << e.what() << endl;
        }

        // 1. Стандартний виняток
        try {
            throw std::bad_exception();
        }
        catch (const std::bad_exception& e) {
            cout << "[bad_exception] Стандартний виняток: " << e.what() << endl;
        }

        // 2. Передача винятку за значенням
        try {
            throw MoneyException();
        }
        catch (MoneyException e) {
            cout << "[by value] Виняток за значенням: " << e.what() << endl;
        }

        // 3. Передача винятку за посиланням
        try {
            throw MoneyException();
        }
        catch (MoneyException& e) {
            cout << "[by reference] Виняток за посиланням: " << e.what() << endl;
        }

        // 4. Передача винятку за вказівником
        try {
            throw new MoneyException();
        }
        catch (MoneyException* e) {
            cout << "[by pointer] Виняток за вказівником: " << e->what() << endl;
            delete e;
        }

    }
    catch (const std::exception& e) {
        cout << "[global catch] Стандартна помилка: " << e.what() << endl;
    }

    return 0;
}
