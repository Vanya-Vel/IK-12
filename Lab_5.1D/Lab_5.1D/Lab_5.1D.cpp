// Lab_05_1D.cpp
// < Величко Іван >
// Лабораторна робота № 5.1D
// Класи з опрацюванням виняткових ситуацій
// Варіант 0.4

#include <iostream>
#include <windows.h>
#include "Functions.h"

using namespace std;

// Власні винятки
class InvalidPointChoiceException : public exception {
public:
    const char* what() const noexcept override {
        return "Невірний вибір точки!";
    }
};

class InvalidIncreaseChoiceException : public exception {
public:
    const char* what() const noexcept override {
        return "Невірний вибір типу збільшення!";
    }
};

// Виняток для неправильного вибору точки
class InvalidPointChoiceСomparison : public exception {
public:
    const char* what() const noexcept override {
        return "Невірний вибір точки для порівняння!";
    }
};

int main() {
    SetConsoleOutputCP(1251);  // Налаштування для коректного виведення кирилиці

    Functions p1, p2;    // Об'єкти класу Functions для точок
    Functions backupP1, backupP2;

    int choice;
    do {
        backupP1 = p1;
        backupP2 = p2;

        cout << "\nМеню:\n";
        cout << "1. Ввести координати точки\n";
        cout << "2. Порівняти точки\n";
        cout << "3. Збільшити координати обраної точки\n";
        cout << "4. Обчислити відстань між двома точками\n";
        cout << "5. Додати точки між собою\n";
        cout << "6. Повернутися до попередніх координат\n";
        cout << "7. Вивести операції інкременту та декременту\n";
        cout << "8. Вивести точки\n";
        cout << "9. Вийти\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        try {

        switch (choice) {
        case 1: {
            // Введення координат для двох точок
            int x, y;
            cout << "Введіть координати для Точки 1 (x y): ";
            cin >> x >> y;
            p1 = Functions(x, y);

            cout << "Введіть координати для Точки 2 (x y): ";
            cin >> x >> y;
            p2 = Functions(x, y);

            cout << "Точки введено!\n";
            break;
        }
        case 2: {
            int pointChoice;
            cout << "Виберіть точку для порівняння (1 - Точка 1, 2 - Точка 2): ";
            cin >> pointChoice;

            if (pointChoice == 1 || pointChoice == 2) {
                if (pointChoice == 1) {
                    if (p1 > p2) {
                        cout << "Точка p1 є більшою за p2.\n";
                    }
                    else {
                        cout << "Потрібно користуватися додатковими параметрами.\n";
                    }
                }
                else {
                    if (p2 > p1) {
                        cout << "Точка p2 є більшою за p1.\n";
                    }
                    else {
                        cout << "Потрібно користуватися додатковими параметрами.\n";
                    }
                }
            }
            else {
                // Генерація винятку для некоректного вибору
                try {
                    throw InvalidPointChoiceСomparison();
                }
                catch (InvalidPointChoiceСomparison e) {
                    cout << "[by value] Виняток за значенням: " << e.what() << endl;
                }

                try {
                    throw InvalidPointChoiceСomparison();
                }
                catch (InvalidPointChoiceСomparison& e) {
                    cout << "[by reference] Виняток за посиланням: " << e.what() << endl;
                }

                try {
                    throw new InvalidPointChoiceСomparison();
                }
                catch (InvalidPointChoiceСomparison* e) {
                    cout << "[by pointer] Виняток за вказівником: " << e->what() << endl << endl;
                    delete e;
                }
            }
            break;
        }
        case 3: {
            int pointChoice;
            cout << "Виберіть точку для переміщення (1 - Точка 1, 2 - Точка 2): ";
            cin >> pointChoice;

            if (pointChoice != 1 && pointChoice != 2) {
                // Викидаємо власний виняток
                try {
                    throw InvalidPointChoiceException();
                }
                catch (InvalidPointChoiceException e) {
                    cout << "[by value] Виняток за значенням: " << e.what() << endl;
                }

                try {
                    throw InvalidPointChoiceException();
                }
                catch (InvalidPointChoiceException& e) {
                    cout << "[by reference] Виняток за посиланням: " << e.what() << endl;
                }

                try {
                    throw new InvalidPointChoiceException();
                }
                catch (InvalidPointChoiceException* e) {
                    cout << "[by pointer] Виняток за вказівником: " << e->what() << endl << endl;
                    delete e;
                }
            }

            int stepX, stepY;
            cout << "Виберіть тип збільшення:\n";
            cout << "1. Збільшити координати X окремо\n";
            cout << "2. Збільшити координати Y окремо\n";
            cout << "3. Збільшити координати X і Y разом\n";
            cout << "Виберіть опцію: ";
            int increaseChoice;
            cin >> increaseChoice;

            if (increaseChoice < 1 || increaseChoice > 3) {
                // Викидаємо власний виняток
                try {
                    throw InvalidPointChoiceException();
                }
                catch (InvalidPointChoiceException e) {
                    cout << "[by value] Виняток за значенням: " << e.what() << endl;
                }

                try {
                    throw InvalidPointChoiceException();
                }
                catch (InvalidPointChoiceException& e) {
                    cout << "[by reference] Виняток за посиланням: " << e.what() << endl;
                }

                try {
                    throw new InvalidPointChoiceException();
                }
                catch (InvalidPointChoiceException* e) {
                    cout << "[by pointer] Виняток за вказівником: " << e->what() << endl << endl;
                    delete e;
                }
            }

            switch (increaseChoice) {
            case 1: {
                cout << "Введіть крок для X: ";
                cin >> stepX;
                if (pointChoice == 1) p1.moveX(stepX);
                else p2.moveX(stepX);
                break;
            }
            case 2: {
                cout << "Введіть крок для Y: ";
                cin >> stepY;
                if (pointChoice == 1) p1.moveY(stepY);
                else p2.moveY(stepY);
                break;
            }
            case 3: {
                cout << "Введіть крок для X: ";
                cin >> stepX;
                cout << "Введіть крок для Y: ";
                cin >> stepY;
                if (pointChoice == 1) {
                    p1.moveX(stepX);
                    p1.moveY(stepY);
                }
                else {
                    p2.moveX(stepX);
                    p2.moveY(stepY);
                }
                break;
            }
            }
            break;
        }
        case 4: {
            // Вивести відстань між точками
            string distText = p1.toString(p2);
            cout << "Відстань між точками: " << p1.distanceFromXtoY(p2) << "  " << distText << endl;
            break;
        }
        case 5: {
            // Додавання точок
            ArithmeticOperations sum = p1 + p2;
            cout << "Результат додавання точок: " << sum << endl;
            break;
        }
        case 6: {
            // Відновлення попередніх координат
            p1 = backupP1;
            p2 = backupP2;
            cout << "Точки відновлено до попередніх значень.\n";
            break;
        }
        case 7: {
            cout << "\nТочки до зміни:\n";
            cout << "p1: " << p1 << endl;
            cout << "p2: " << p2 << endl << endl;

            // Префіксний інкремент для p1
            cout << "Точка 1 після преінкременту ++x: " << ++p1 << endl;

            // Постфіксний інкремент для p2
            cout << "Точка 2 після постінкременту x++: " << p2++ << endl;
            cout << "p1: " << p1 << endl;
            cout << "p2: " << p2 << endl << endl;

            // Префіксний декремент для p1
            cout << "Точка 1 після предекременту --y: " << --p1 << endl;

            // Постфіксний декремент для p2
            cout << "Точка 2 після постдекременту y--: " << p2-- << endl;
            cout << "p1: " << p1 << endl;
            cout << "p2: " << p2 << endl << endl;
            break;
        }
        case 8: {
            cout << "Виведені точки!\n";
            cout << "1 " << p1 << endl;
            cout << "2 " << p2 << endl << endl;
            break;
        }
        case 9: {
            cout << "До побачення!\n";
            break;
        }
        default:
            cout << "Невірний вибір, спробуйте ще раз.\n";
        }

         }
         catch (const InvalidPointChoiceСomparison& e) {
             cout << "Помилка: " << e.what() << endl;
         }
         catch (const InvalidPointChoiceException& e) {
             cout << "Помилка: " << e.what() << endl;  // Обробка власного винятку
         }
         catch (const InvalidIncreaseChoiceException& e) {
             cout << "Помилка: " << e.what() << endl;  // Обробка власного винятку
         }
         catch (const invalid_argument& e) {
             cout << "Помилка: Невірний ввід, спробуйте ще раз.\n";
         }
         catch (const exception& e) {
             cout << "Стандартна помилка: " << e.what() << endl;  // Обробка стандартного винятку
         }

    } while (choice != 9);

    return 0;
}
