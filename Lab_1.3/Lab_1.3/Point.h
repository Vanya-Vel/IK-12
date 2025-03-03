#pragma once // Запобігає кількаразовому підключенню цього заголовочного файлу

#include <string> // Підключаємо стандартну бібліотеку для роботи з рядками

using namespace std;
class Point
{
private:
    int x = 0, y = 0;

public:
    // Гетери для отримання координат
    int getX() const { return x; } // Повертає координату X
    int getY() const { return y; } // Повертає координату Y

    // Сетери для встановлення координат
    void setX(int value) { x = value; }; // Встановлює координату X
    void setY(int value) { y = value; }; // Встановлює координату Y

    // Метод для переміщення точки по осі X
    void moveX(int stepX);

    // Метод для переміщення точки по осі Y
    void moveY(int stepY);

    // Метод для обчислення відстані між двома точками
    double distanceFromXtoY(const Point& other) const;

    // Ініціалізація точки з координатами
    bool Init(int CoorX, int CoorY);

    // Виведення координат точки
    void Display() const;

    // Зчитування координат точки з вводу користувача
    void Read();

    // Переміщення точки на задану кількість одиниць по осях
    void displacement();

    // Перетворення об'єкта на строкове подання
    string toString(const Point& other) const;

    // Перетворення числа на текстове представлення
    string ToNumeral(int number) const;
};
