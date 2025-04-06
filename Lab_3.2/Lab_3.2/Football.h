#pragma once
#include "SportGame.h"

// Похідний клас "Футбол"
class Football : public SportGame {
private:
    string league;    // Назва ліги

public:
    Football(string n = "", int p = 0, string l = "");   // Конструктор
    Football(const Football& other);                     // Конструктор копіювання
    Football& operator=(const Football& other);          // Оператор присвоєння
    void display(ostream& os) const;                     // Виведення
    void input(istream& is);                             // Введення
};
