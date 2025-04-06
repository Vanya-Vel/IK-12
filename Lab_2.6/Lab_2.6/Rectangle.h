#pragma once
#include <iostream>
#include <string>
using namespace std;

class Rectangle {
public:
    class Pair {  // Внутрішній клас
    private:
        int first, second;
        static int counter;  // Лічильник об'єктів Pair

    public:
        Pair();  // Конструктор без аргументів
        Pair(int first, int second);  // Конструктор з параметрами
        Pair(const Pair& p);  // Конструктор копіювання
        ~Pair(void);  // Деструктор

        static int getCounter() {
            return counter;
        }  // Метод для отримання кількості об'єктів Pair

        // Операції доступу
        int getFirst() const { return first; }
        void setFirst(int first) { this->first = first; }
        int getSecond() const { return second; }
        void setSecond(int second) { this->second = second; }

        // Метод для обчислення добутку
        int multiply() const { return first * second; }

        // Введення та виведення
        friend istream& operator>>(istream& in, Pair& p);
        friend ostream& operator<<(ostream& out, const Pair& p);

        // Перетворення в рядок
        string toString() const;

        // Операції інкременту та декременту
        Pair& operator++();  // Префікс
        Pair operator++(int);  // Постфікс
        Pair& operator--();  // Префікс
        Pair operator--(int);  // Постфікс
    };

private:
    Pair sides;  // Використання Pair для збереження сторін
    static int counter;  // Лічильник об'єктів Rectangle

public:
    Rectangle();  // Конструктор без аргументів
    Rectangle(const Pair& sides);  // Конструктор з параметрами
    Rectangle(const Rectangle& r);  // Конструктор копіювання
    ~Rectangle(void);  // Деструктор

    static int getCounter() {
        return counter;
    }// Метод для отримання кількості об'єктів Rectangle

    // Методи доступу
    Pair getPair() const { return sides; }
    void setPair(const Pair& sides) { this->sides = sides; }

    // Обчислення периметра та площі
    int getPerimeter() const {
        return 2 * (sides.getFirst() + sides.getSecond());
    }
    int getArea() const { return sides.multiply(); }

    // Операція присвоєння
    Rectangle& operator=(const Rectangle& r);

    // Операції інкременту та декременту
    Rectangle& operator++();  // Префікс
    Rectangle operator++(int);  // Постфікс
    Rectangle& operator--();  // Префікс
    Rectangle operator--(int);  // Постфікс

    // Введення та виведення
    friend ostream& operator<<(ostream& out, const Rectangle& r);
    friend istream& operator>>(istream& in, Rectangle& r);

    // Перетворення в рядок
    string toString() const;
};
