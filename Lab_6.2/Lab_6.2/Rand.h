#pragma once
#include <iostream>
#include <functional>
using namespace std;

class Rand
{
public:
    // Оголошення типів даних для зручності використання
    using value_type = pair<double, double>;  // Тип пари (x, p), де x — значення, p — ймовірність
    using size_type = size_t;                // Тип для зберігання розміру (кількість елементів)

private:
    value_type* data;       // Масив пар (x, p), що зберігають значення та ймовірності
    size_type count;        // Кількість елементів у масиві
    size_type capacity;     // Ємність масиву (максимальна кількість елементів, яку він може зберігати)

public:
    // Конструктор з параметром на кількість елементів
    Rand(size_type cap = 10);
    // Конструктор копіювання
    Rand(const Rand& other);
    // Оператор присвоєння
    Rand& operator=(const Rand& other);
    // Деструктор для очищення пам'яті
    ~Rand();

    // Метод для додавання пари (x, p) в масив
    void add(double x, double p);
    // Метод для очищення масиву (видалення всіх елементів)
    void clear();

    // Метод для обчислення математичного очікування
    double mean() const;
    // Метод для обчислення дисперсії
    double variance() const;

    // Метод для обчислення інтегралу функції f(x) методом Монте-Карло
    double monteCarloIntegral(function<double(double)> f, double a, double b, size_type N) const;

    // Метод для виведення вмісту масиву (пар x, p)
    void print() const;
    // Метод для отримання кількості елементів в масиві
    size_type size() const;
};
