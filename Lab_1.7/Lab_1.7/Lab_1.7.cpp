#include <iostream>
#include <string>
#include <windows.h>
#include "Bankomat.h"

using namespace std;

int main() {
    // Встановлення кодування для кирилиці
    SetConsoleOutputCP(1251);  // Для виведення кирилиці в Windows

    Bankomat atm;
    string atmID;
    double minAmount = 100, maxAmount = 5000;

    // Введення ID банкомату
    cout << "Введіть ідентифікаційний номер банкомату (29 цифр): ";
    cin >> atmID;

    // Ініціалізація банкомату
    atm.Init(atmID, minAmount, maxAmount);

    if (!atm.validateATMID(atmID)) {
        std::cout << "Невірний ідентифікаційний номер банкомату! Повинно бути 29 цифр.\n";
        return 1;
    }

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Перевірити баланс\n";
        cout << "2. Зняти гроші\n";
        cout << "3. Внести гроші\n";
        cout << "4. Показати ліміти зняття\n";
        cout << "0. Вихід\n";
        cout << "Оберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {  // Перевірка балансу
            atm.displayBalance();
            atm.displayBalanceInWords();
            break;
        }
        case 2: {  // Зняття грошей
            double amount;
            cout << "Введіть суму для зняття: ";
            cin >> amount;

            cout << "Ви хочете зняти суму " << amount << " грн?\n";
            cout << "0 - ні, 1 - так: ";
            int confirm;
            std::cin >> confirm;

            if (confirm == 1) {
                atm.withdrawMoney(amount);
            }
            else {
                std::cout << "Операція скасована.\n";
            }
            break;
        }
        case 3: {
            double amount;
            cout << "Введіть суму для внесення: ";
            cin >> amount;

            atm.depositMoney(amount);
            break;
        }
        case 4: {  // Показ лімітів зняття
            atm.showLimits();
            break;
        }
        case 0: {
            std::cout << "Вихід з програми.\n";
            break;
        }
        default: {
            std::cout << "Невірний вибір, спробуйте ще раз.\n";
            break;
        }
        }

    } while (choice != 0);

    return 0;
}
