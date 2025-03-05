#include "Bankomat.h"

using namespace std; // Додаємо простір імен std для скорочення запису

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
