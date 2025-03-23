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
    int getFirst() const;
    void setFirst(int first);
    int getSecond() const;
    void setSecond(int second);

    // Метод для обчислення добутку
    int multiply() const;

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
