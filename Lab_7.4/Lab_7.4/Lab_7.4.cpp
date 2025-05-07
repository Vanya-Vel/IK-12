#include <iostream>
#include <map>
#include <string>
#include <limits>

using namespace std;

struct Employee {
    string initials;
    string position;
    int year;
    double salary;
};

// Додавання службовця до колекції
void addEmployee(map<string, Employee>& employees) {
    string surname;
    Employee emp;

    cout << "Введіть прізвище: ";
    getline(cin >> ws, surname);

    cout << "Введіть ініціали: ";
    getline(cin, emp.initials);

    cout << "Введіть посаду: ";
    getline(cin, emp.position);

    cout << "Введіть рік прийому на роботу: ";
    while (!(cin >> emp.year) || emp.year < 1900 || emp.year > 2100) {
        cout << "Помилка! Введіть коректний рік (1900–2100): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введіть оклад: ";
    while (!(cin >> emp.salary) || emp.salary < 0) {
        cout << "Помилка! Оклад не може бути від'ємним. Повторіть: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    employees[surname] = emp;
    cout << "Службовця додано успішно.\n";
}

// Перегляд усіх службовців
void viewEmployees(const map<string, Employee>& employees) {
    if (employees.empty()) {
        cout << "Колекція порожня.\n";
        return;
    }

    // Замість структурованих зв'язків, використовуйте звичайні ітератори
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        const string& surname = it->first;
        const Employee& emp = it->second;

        cout << "Прізвище: " << surname << "\n"
            << "Ініціали: " << emp.initials << "\n"
            << "Посада: " << emp.position << "\n"
            << "Рік прийому: " << emp.year << "\n"
            << "Оклад: " << emp.salary << "\n"
            << "------------------------\n";
    }
}

// Пошук службовця за прізвищем
void findEmployee(const map<string, Employee>& employees) {
    string surname;
    cout << "Введіть прізвище службовця для пошуку: ";
    getline(cin >> ws, surname);

    auto it = employees.find(surname);
    if (it != employees.end()) {
        const Employee& emp = it->second;
        cout << "Знайдено:\n"
            << "Ініціали: " << emp.initials << "\n"
            << "Посада: " << emp.position << "\n"
            << "Рік прийому: " << emp.year << "\n"
            << "Оклад: " << emp.salary << "\n";
    }
    else {
        cout << "Службовця з таким прізвищем не знайдено.\n";
    }
}

// Меню програми
     {
    map<string, Employee> employees;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Додати службовця\n";
        cout << "2. Переглянути всіх службовців\n";
        cout << "3. Знайти службовця за прізвищем\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";

        while (!(cin >> choice) || choice < 0 || choice > 3) {
            cout << "Помилка! Введіть число від 0 до 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // очистити буфер

        switch (choice) {
        case 1: addEmployee(employees); break;
        case 2: viewEmployees(employees); break;
        case 3: findEmployee(employees); break;
        case 0: cout << "Завершення роботи.\n"; break;
        }
    } while (choice != 0);
}

#include "windows.h"

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    menu();

    return 0;
}
