#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Vector
{

private:
    static const size_t MAX_SIZE = 100; // Максимально можливий розмір масиву
    int data[MAX_SIZE];  // Масив фіксованого розміру
    size_t size;         // Максимальна кількість елементів
    size_t count;        // Поточна кількість елементів
    int N;

public:
    Vector();                     // Конструктор за умовчанням
    Vector(size_t, int);          // Конструктор з двома параметрами (ініціалізація)
    Vector(const Vector&);        // Конструктор копіювання

    size_t getSize() const { return size; }
    size_t getCount() const { return count; }
    void setCount(size_t value) { 
        if (value > size) cout << "count не може бути більше за size" << endl;
        count = value;
    }

    double NormVector() const;
    int summa();
    string toString(double) const;                          // Перетворення числа на текстове представлення

    Vector operator * (const Vector&);                      // Операція множення
    bool operator == (const Vector& other) const;           // Операція присвоєння

    Vector& operator ++();     // Префіксний інкремент
    Vector operator ++(int);   // Постфіксний інкремент
    Vector& operator --();     // Префіксний декремент
    Vector operator --(int);   // Постфіксний декремент

    // Ввід/вивід
    friend ostream& operator << (ostream&, const Vector&);
    friend istream& operator >> (istream&, Vector&);
};