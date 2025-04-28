#pragma once
#include <iostream>
#include <functional>
#include <list>  // Замість масиву використовуємо двонапрямлений список
using namespace std;

class Rand
{
public:
    // Оголошення типів даних для зручності використання
    using value_type = pair<double, double>;  // Тип пари (x, p), де x — значення, p — ймовірність
    using size_type = size_t;                // Тип для зберігання розміру (кількість елементів)
    using iterator = list<value_type>::iterator;  // Ітератор для двонапрямленого списку

private:
    list<value_type> data;  // Двонапрямлений список для зберігання пар (x, p) замість масиву

public:
    // Конструктор за замовчуванням
    Rand();
    // Конструктор копіювання
    Rand(const Rand& other);
    // Оператор присвоєння
    Rand& operator=(const Rand& other);
    // Деструктор (не потрібно, оскільки використовуємо контейнер STL)
    ~Rand() = default;

    // Метод для додавання пари (x, p) в список
    void add(double x, double p);
    // Метод для очищення списку
    void clear();

    // Метод для обчислення математичного очікування
    double mean() const;
    // Метод для обчислення дисперсії
    double variance() const;

    // Метод для обчислення інтегралу функції f(x) методом Монте-Карло
    double monteCarloIntegral(function<double(double)> f, double a, double b, size_type N) const;

    // Метод для виведення вмісту списку (пар x, p)
    void print() const;
    // Метод для отримання кількості елементів у списку
    size_type size() const;

    // Методи для отримання ітераторів
    iterator begin() { return data.begin(); }  // Використовуємо ітератори для доступу до елементів списку
    iterator end() { return data.end(); }      // Ітератори заміняють індексацію для доступу до елементів
};
