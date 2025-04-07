// Lab_03_3F.cpp
// < Величко Іван >
// Лабораторна робота № 3.3F
// Успадкування замість композиції
// Варіант 0.4

#include <iostream>
#include "Functions.h"
#include "Money.h"
#include <windows.h>
#include <string>

using namespace std;

int main() {

    // Встановлення кодування для кирилиці
    SetConsoleOutputCP(1251);  // Для виведення кирилиці в Windows

    // Введення даних для банкомату
    string atmID;
    double minAmount, maxAmount;

    Functions atm;
    cout << "Введіть ID банкомату: ";
    cin >> atmID;
    if (!atm.validateATMID(atmID)) {
        cout << "Невірний ідентифікаційний номер банкомату! Повинно бути 29 цифр.\n";
        return 1;
    }

    cout << "Введіть мінімальну суму для зняття: ";
    cin >> minAmount;

    cout << "Введіть максимальну суму для зняття: ";
    cin >> maxAmount;
    cout << "Count object = " << Object::Count() << endl << endl;

    // Використовуємо конструктор з параметрами для створення банкомату
    atm = Functions(atmID, minAmount, maxAmount);

    cout << "Банкомат ID: " << atmID << endl;
    atm.displayBalance(); // Вивести баланс банкомату

    // Тепер продовжуємо з додаванням грошей у банкомат через switch
    double amount;
    int choice;
    while (true) {
        cout << "\nОберіть номінал для внесення грошей:\n";
        cout << "1. 500 грн\n";
        cout << "2. 200 грн\n";
        cout << "3. 100 грн\n";
        cout << "4. 50 грн\n";
        cout << "5. 20 грн\n";
        cout << "6. 10 грн\n";
        cout << "7. 5 грн\n";
        cout << "8. 2 грн\n";
        cout << "9. 1 грн\n";
        cout << "10. 50 копійок\n";
        cout << "11. 25 копійок\n";
        cout << "12. 10 копійок\n";
        cout << "13. 5 копійок\n";
        cout << "14. 2 копійки\n";
        cout << "15. 1 копійка\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 0) {
            break;  // Вихід з циклу
        }

        cout << "Введіть кількість: ";
        cin >> amount;

        // Операція внесення грошей
        switch (choice) {
        case 1:
            atm.depositMoney(500.0 * amount);
            break;
        case 2:
            atm.depositMoney(200.0 * amount);
            break;
        case 3:
            atm.depositMoney(100.0 * amount);
            break;
        case 4:
            atm.depositMoney(50.0 * amount);
            break;
        case 5:
            atm.depositMoney(20.0 * amount);
            break;
        case 6:
            atm.depositMoney(10.0 * amount);
            break;
        case 7:
            atm.depositMoney(5.0 * amount);
            break;
        case 8:
            atm.depositMoney(2.0 * amount);
            break;
        case 9:
            atm.depositMoney(1.0 * amount);
            break;
        case 10:
            atm.depositMoney(0.5 * amount);
            break;
        case 11:
            atm.depositMoney(0.25 * amount);
            break;
        case 12:
            atm.depositMoney(0.1 * amount);
            break;
        case 13:
            atm.depositMoney(0.05 * amount);
            break;
        case 14:
            atm.depositMoney(0.02 * amount);
            break;
        case 15:
            atm.depositMoney(0.01 * amount);
            break;
        default:
            cout << "Невірний вибір.\n";
            continue;
        }

        atm.displayBalance();  // Показуємо оновлений баланс
    }

    // Виведення балансу в буквений формат
    cout << atm;  // Використовуємо перевантажений оператор виводу для балансу в словах

    // Тепер ви можете вводити суму для зняття
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

    // Копіювання банкомату за допомогою копіювального конструктора
    Functions atmCopy = atm;  // Це викликає копіювальний конструктор
    cout << "\nКопія банкомату баланс:\n";
    atmCopy.displayBalance(); // Перевіримо баланс у копії
    cout << "Count object = " << Object::Count() << endl << endl;

    return 0;
}
