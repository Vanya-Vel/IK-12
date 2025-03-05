#pragma once
#include <string>
using namespace std;

class Rectangle
{
private:
    // Вкладений клас для пари сторін прямокутника
    class Pair
    {
    private:
        int first, second;  // Перша і друга сторони

    public:
        // Геттери та сеттери для сторін прямокутника
        int getFirst() const { return first; }
        void setFirst(int first) { this->first = first; }
        int getSecond() const { return second; }
        void setSecond(int second) { this->second = second; }

        // Обчислення добутку сторін
        int multiply() const { return first * second; }

        // Ініціалізація пари сторін
        void Init(int first, int second);

        // Виведення сторін
        void Display() const;

        // Зчитування сторін
        void Read();
    };

    // Зберігає пару сторін прямокутника
    Pair sides;

public:
    // Геттер і сеттер для пари сторін
    Rectangle::Pair getPair() const { return sides; }
    void setPair(Rectangle::Pair sides) { this->sides = sides; }

    // Обчислення периметра прямокутника
    int getPerimeter() const { return 2 * (sides.getFirst() + sides.getSecond()); }

    // Обчислення площі прямокутника
    int getArea() const { return sides.multiply(); }

    // Ініціалізація прямокутника
    void Init(Rectangle::Pair sides);

    // Виведення інформації про прямокутник
    void Display() const;

    // Зчитування сторін прямокутника
    void Read();
};
