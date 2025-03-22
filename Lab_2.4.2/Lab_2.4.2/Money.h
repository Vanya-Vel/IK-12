#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Money {
    static const size_t MAX_SIZE = 100; // Максимально можливий розмір масиву
    int summa[MAX_SIZE];  // Масив фіксованого розміру
    size_t size;         // Максимальна кількість елементів
    size_t count;        // Поточна кількість елементів

public:
    // Конструктори
    Money();
    Money(size_t, size_t);
    Money(const Money&);
    
    // **Константні методи зчитування (геттери)**
    size_t getSize() const { return size; }
    size_t getCount() const { return count; }
    int getData(size_t index) const {
        if (index < count) return summa[index];
        cout << "Помилка: індекс виходить за межі!" << endl;
        return -1; // Значення за замовчуванням у разі помилки
    }

    // **Методи запису (сеттери)**
    void setSize(size_t value) {
        if (value > MAX_SIZE) {
            cout << "Помилка: size не може бути більше за MAX_SIZE" << endl;
            return;
        }
        size = value;
    }
    void setCount(size_t value) {
        if (value > size) {
            cout << "Помилка: count не може бути більше за size" << endl;
            return;
        }
        count = value;
    }
    void setData(size_t index, int value) {
        if (index < count) summa[index] = value;
        else cout << "Помилка: індекс виходить за межі!" << endl;
    }

    // Оператори
    Money operator = (const Money&);   // Присвоєння

    // Перетворення числа на текстове представлення
    string toString() const;

    // Ввід/вивід
    friend ostream& operator << (ostream&, const Money&);
    friend istream& operator >> (istream&, Money&);
};
