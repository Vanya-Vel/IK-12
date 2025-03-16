﻿#include <iostream>
#include <windows.h>
#include "Point.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    Point p1, p2;
    Point backupP1, backupP2;  // Резервні копії точок для повернення

    int choice;
    do {
        // Збереження резервної копії точок
        backupP1 = p1;
        backupP2 = p2;

        // Меню для вибору операцій
        cout << "\nМеню:\n";
        cout << "1. Ввести координати точки\n";
        cout << "2. Збільшити координати обраної точки\n";
        cout << "3. Обчислити відстань між двома точками\n";
        cout << "4. Додати точки між собою\n";
        cout << "5. Повернутися до попередніх координат\n";
        cout << "6. Вивести операції інктементу та дектементу\n";
        cout << "7. Вийти\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Введення координат для двох точок
            int x, y;
            cout << "Введіть координати для Точки 1 (x y): ";
            cin >> x >> y;
            p1 = Point(x, y);

            cout << "Введіть координати для Точки 2 (x y): ";
            cin >> x >> y;
            p2 = Point(x, y);

            cout << "Точки введено!\n";
            break;
        }
        case 2: {
            int pointChoice;
            cout << "Виберіть точку для переміщення (1 - Точка 1, 2 - Точка 2): ";
            cin >> pointChoice;

            if (pointChoice == 1 || pointChoice == 2) {
                int stepX, stepY;
                cout << "Виберіть тип збільшення:\n";
                cout << "1. Збільшити координати X окремо\n";
                cout << "2. Збільшити координати Y окремо\n";
                cout << "3. Збільшити координати X і Y разом\n";
                cout << "Виберіть опцію: ";
                int increaseChoice;
                cin >> increaseChoice;

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
            }
            else {
                cout << "Невірний вибір точки.\n";
            }
            break;
        }
        case 3: {
            // Вивести відстань між точками
            string distText = p1.toString(p2);
            cout << "Відстань між точками: " << p1.distanceFromXtoY(p2) << "  " << distText << endl;
            break;
        }
        case 4: {
            // Додавання точок
            Point sum = p1 + p2;
            cout << "Результат додавання точок: " << sum << endl;
            break;
        }
        case 5: {
            // Відновлення попередніх координат
            p1 = backupP1;
            p2 = backupP2;
            cout << "Точки відновлено до попередніх значень.\n";
            break;
        }
        case 6: {
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
        case 7: {
            cout << "До побачення!\n";
            break;
        }
        default:
            cout << "Невірний вибір, спробуйте ще раз.\n";
        }
    } while (choice != 7);

    return 0;
}
