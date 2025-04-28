#include "Rand.h"
#include <stdexcept>
#include <random>
#include <cmath>

// Конструктор за замовчуванням
Rand::Rand() = default;

// Конструктор копіювання
Rand::Rand(const Rand & other) : data(other.data) {}

// Оператор присвоєння
Rand& Rand::operator=(const Rand & other)
{
    if (this != &other)  // Перевірка на самоприсвоєння
    {
        data = other.data;  // Копіюється вміст списку
    }
    return *this;  // Повернення поточного об'єкта
}

// Метод для додавання пари (x, p) в список
void Rand::add(double x, double p)
{
    if (p < 0.0)
        throw invalid_argument("Ймовірність не може бути від'ємною.");  // Перевірка на від'ємну ймовірність

    data.push_back({ x, p });  // Додавання пари в кінець списку
}

// Метод для очищення списку
void Rand::clear()
{
    data.clear();  // Очищення списку
}

// Метод для обчислення математичного очікування
double Rand::mean() const
{
    double sum = 0.0;
    for (const auto& pair : data)
        sum += pair.first * pair.second;  // Підсумовування x * p для кожної пари
    return sum;  // Повертається математичне очікування
}

// Метод для обчислення дисперсії
double Rand::variance() const
{
    double m = mean();  // Математичне очікування
    double sum = 0.0;
    for (const auto& pair : data)
        sum += (pair.first - m) * (pair.first - m) * pair.second;  // Підсумовування (x - m)^2 * p
    return sum;  // Повертається дисперсія
}

// Метод для обчислення інтегралу функції f(x) методом Монте-Карло
double Rand::monteCarloIntegral(function<double(double)> f, double a, double b, size_type N) const
{
    if (a >= b || N == 0)
        throw invalid_argument("Некоректні параметри для інтегрування.");  // Перевірка на коректність параметрів

    random_device rd;  // Ініціалізація випадкового генератора
    mt19937 gen(rd());  // Генератор випадкових чисел
    uniform_real_distribution<> dis(a, b);  // Розподіл для випадкових чисел в межах [a, b]

    double sum = 0.0;
    for (size_type i = 0; i < N; ++i)
    {
        double x = dis(gen);  // Генерація випадкової точки
        sum += f(x);  // Обчислення значення функції в точці x
    }
    return (b - a) * sum / static_cast<double>(N);  // Обчислення та повернення інтегралу
}

// Метод для виведення вмісту списку (пар x, p)
void Rand::print() const
{
    for (const auto& pair : data)
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;  // Виведення пар (x, p)
}

// Метод для отримання кількості елементів у списку
Rand::size_type Rand::size() const
{
    return data.size();  // Повертається кількість елементів у списку
}
