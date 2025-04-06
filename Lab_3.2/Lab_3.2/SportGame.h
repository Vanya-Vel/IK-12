#pragma once
#include <iostream>
#include <string>
using namespace std;

// Базовий клас "Спортивна гра"
class SportGame {
protected:
    string name;         // Назва гри
    int playersCount;    // Кількість гравців

public:
    SportGame(string n = "", int p = 0);                // Конструктор
    SportGame(const SportGame& other);                  // Конструктор копіювання
    SportGame& operator=(const SportGame& other);       // Оператор присвоєння
    bool operator==(const SportGame& other) const;  // Додайте цей оператор у заголовок
    void display(ostream& os) const;                    // Виведення
    void input(istream& is);                            // Введення
};
