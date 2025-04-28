#include "Rand.h"
#include <stdexcept>
#include <random>
#include <cmath>

// Конструктор, ініціалізує кількість елементів та ємність масиву
Rand::Rand(size_type cap) : count(0), capacity(cap)
{
    data = new value_type[capacity];  // Виділяється пам'ять для масиву
}

// Конструктор копіювання
Rand::Rand(const Rand& other) : count(other.count), capacity(other.capacity)
{
    data = new value_type[capacity];  // Виділяється пам'ять для нового масиву
    for (size_type i = 0; i < count; ++i)
        data[i] = other.data[i];  // Копіюються дані з іншого об'єкта
}

// Оператор присвоєння
Rand& Rand::operator=(const Rand& other)
{
    if (this != &other)  // Перевірка на самоприсвоєння
    {
        delete[] data;  // Видалення попередньо виділеної пам'яті
        capacity = other.capacity;  // Оновлення ємності
        count = other.count;  // Оновлення кількості елементів
        data = new value_type[capacity];  // Виділення пам'яті для нового масиву
        for (size_type i = 0; i < count; ++i)
            data[i] = other.data[i];  // Копіювання даних
    }
    return *this;  // Повернення поточного об'єкта
}

// Деструктор
Rand::~Rand()
{
    delete[] data;  // Звільнення пам'яті, виділеної під масив
}

// Метод для додавання пари (x, p) в масив
void Rand::add(double x, double p)
{
    if (p < 0.0)
        throw invalid_argument("Ймовірність не може бути від'ємною.");  // Перевірка на від'ємну ймовірність

    if (count >= capacity)
        throw overflow_error("Перевищено місткість масиву.");  // Перевірка на перевищення місткості масиву

    data[count++] = { x, p };  // Додавання пари в масив
}

// Метод для очищення масиву
void Rand::clear()
{
    count = 0;  // Очищення масиву (скидається кількість елементів)
}

// Метод для обчислення математичного очікування
double Rand::mean() const
{
    double sum = 0.0;
    for (size_type i = 0; i < count; ++i)
        sum += data[i].first * data[i].second;  // Підсумовування x * p для кожної пари
    return sum;  // Повертається математичне очікування
}

// Метод для обчислення дисперсії
double Rand::variance() const
{
    double m = mean();  // Математичне очікування
    double sum = 0.0;
    for (size_type i = 0; i < count; ++i)
        sum += (data[i].first - m) * (data[i].first - m) * data[i].second;  // Підсумовування (x - m)^2 * p
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

// Метод для виведення вмісту масиву (пар x, p)
void Rand::print() const
{
    for (size_type i = 0; i < count; ++i)
        cout << "(" << data[i].first << ", " << data[i].second << ")" << endl;  // Виведення пар (x, p)
}

// Метод для отримання кількості елементів у масиві
Rand::size_type Rand::size() const
{
    return count;  // Повертається кількість елементів у масиві
}
