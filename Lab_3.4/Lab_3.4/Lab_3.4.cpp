#include <iostream>
#include <string>
#include <windows.h>
#include "Factory.h"

using namespace std;

void clearInput() {
    cin.clear();
    while (cin.get() != '\n');
}

int getInt(const string& prompt) {
    int num;
    cout << prompt;
    while (!(cin >> num)) {
        cout << "Невірне значення. Спробуйте ще раз: ";
        clearInput();
    }
    clearInput();
    return num;
}

void displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Створити SymString\n";
    cout << "2. Створити BinString\n";
    cout << "3. Показати всі об'єкти\n";
    cout << "4. Видалити об'єкт\n";
    cout << "5. Використати операцію віднімання для SymString\n";
    cout << "6. Використати операцію віднімання для BinString\n";
    cout << "7. Копіювати або присвоїти значення\n";
    cout << "0. Вийти\n";
    cout << "Вибір: ";
}

void processMenuChoice(Factory& factory, int choice) {
    switch (choice) {
    case 1: {
        string id, val;
        cout << "Введіть ID: ";
        getline(cin, id);
        cout << "Введіть значення: ";
        getline(cin, val);
        factory.createSymString(id, val);
        break;
    }
    case 2: {
        string id, val;
        cout << "Введіть ID: ";
        getline(cin, id);
        cout << "Введіть двійкове значення: ";
        getline(cin, val);
        factory.createBinString(id, val);
        break;
    }
    case 3:
        factory.showAll();
        break;

    case 4: {
        factory.showAll();
        int index = getInt("Введіть індекс об'єкта для видалення: ");
        factory.deleteObject(index);
        break;
    }

    case 5: {
        factory.showAll();
        int i1 = getInt("Індекс SymString (основний): ");
        int i2 = getInt("Індекс SymString (підрядок): ");
        SymString* s1 = factory.getSymString(i1);
        SymString* s2 = factory.getSymString(i2);
        if (s1 && s2) {
            SymString result = *s1 - *s2;
            result.show();
        }
        else {
            cout << "Невірні індекси.\n";
        }
        break;
    }

    case 6: {
        factory.showAll();
        int i1 = getInt("Індекс BinString (основний): ");
        int i2 = getInt("Індекс BinString (віднімання): ");
        BinString* b1 = factory.getBinString(i1);
        BinString* b2 = factory.getBinString(i2);
        if (b1 && b2) {
            string result = *b1 - *b2;
            cout << "Результат: " << result << endl;
        }
        else {
            cout << "Невірні індекси.\n";
        }
        break;
    }

    case 7: {
        factory.showAll();
        int i = getInt("Введіть індекс об'єкта для копіювання: ");
        cout << "Тип (1 - SymString, 2 - BinString): ";
        int type;
        cin >> type;
        clearInput();
        string newId;
        cout << "Новий ID: ";
        getline(cin, newId);
        if (type == 1) {
            SymString* s = factory.getSymString(i);
            if (s) factory.createSymString(newId, s->getValue());
            else cout << "Об'єкт не знайдено.\n";
        }
        else if (type == 2) {
            BinString* b = factory.getBinString(i);
            if (b) factory.createBinString(newId, b->getValue());
            else cout << "Об'єкт не знайдено.\n";
        }
        else {
            cout << "Невірний тип.\n";
        }
        break;
    }

    case 0:
        cout << "Завершення програми.\n";
        break;

    default:
        cout << "Невірний вибір.\n";
    }
}

int main() {
    // Встановлення кодування для кирилиці (для виведення в консоль)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Factory factory;
    int choice;

    do {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Невірне значення. Спробуйте ще раз.\n";
            clearInput();
            continue;
        }

        clearInput();
        processMenuChoice(factory, choice);

    } while (choice != 0);

    return 0;
}
