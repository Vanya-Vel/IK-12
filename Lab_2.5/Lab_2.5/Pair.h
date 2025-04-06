#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair {
private:
    int first, second;

public:
    Pair();  // Конструктор без аргументів
    Pair(int first, int second);  // Конструктор з параметрами
    Pair(const Pair& p);  // Конструктор копіювання

    // Операції доступу
    int getFirst() const { return first; }
    void setFirst(int first) { this->first = first; }
    int getSecond() const { return second; }
    void setSecond(int second) { this->second = second; }

    // Метод для обчислення добутку
    int multiply() const { return first * second; }

    // Виведення значень
    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);

    // Перетворення в рядок
    string toString() const;

    // Операція інкременту (префіксна)
    Pair& operator++();

    // Операція інкременту (постфіксна)
    Pair operator++(int);

    // Операція декременту (префіксна)
    Pair& operator--();

    // Операція декременту (постфіксна)
    Pair operator--(int);
};
