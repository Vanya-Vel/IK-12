
#include "SportGame.h"

// Конструктор із параметрами
SportGame::SportGame(string n, int p) : name(n), playersCount(p) {}

// Конструктор копіювання
SportGame::SportGame(const SportGame& other) {
    name = other.name;
    playersCount = other.playersCount;
}

// Оператор присвоєння
SportGame& SportGame::operator=(const SportGame& other) {
    if (this != &other) {
        name = other.name;
        playersCount = other.playersCount;
    }
    return *this;
}

// Оператор порівняння
bool SportGame::operator==(const SportGame& other) const {
    return name == other.name && playersCount == other.playersCount;
}

// Виведення інформації про гру
void SportGame::display(ostream& os) const {
    os << "Спортивна гра: " << name << ", Гравців: " << playersCount;
}

// Введення інформації з потоку
void SportGame::input(istream& is) {
    is >> name >> playersCount;
}
