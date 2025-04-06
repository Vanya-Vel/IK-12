
#include "Football.h"

// Конструктор із параметрами
Football::Football(string n, int p, string l)
    : SportGame(n, p), league(l) {}

// Конструктор копіювання
Football::Football(const Football& other)
    : SportGame(other), league(other.league) {}

// Оператор присвоєння
Football& Football::operator=(const Football& other) {
    if (this != &other) {
        SportGame::operator=(other);
        league = other.league;
    }
    return *this;
}

// Виведення інформації про футбол
void Football::display(ostream& os) const {
    SportGame::display(os);
    os << ", Ліга: " << league;
}

// Введення інформації з потоку
void Football::input(istream& is) {
    SportGame::input(is);
    is >> league;
}
