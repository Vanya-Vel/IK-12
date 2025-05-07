#include <iostream>
#include "windows.h"
using namespace std;

// Інтерфейс, що описує функтори - унарні предикати
template<class T>
class Predicate
{
public:
    virtual bool operator () (T x) = 0;
};

// Реалізуємо інтерфейс функтором - перевірка, чи значення від'ємне
template<class T>
class Negative : public Predicate<T>
{
public:
    virtual bool operator () (T x)
    {
        return x < 0;
    }
};

// Функція видалення елемента за значенням
template<class T>
int erase(T* begin, T* end, T* to, T value)
{
    int n = 0;
    for (T* from = begin; from < end; from++)
    {
        if (*from != value)
        {
            *to = *from;
            to++;
            n++;
        }
    }
    return n;
}

// Функція для видалення елементів, які задовольняють умови предикату
template<class T>
int erase_if(T* begin, T* end, T* to, Predicate<T>& p)
{
    int n = 0;
    for (T* from = begin; from < end; from++)
    {
        if (!p(*from)) // Якщо елемент не задовольняє умови предикату
        {
            *to = *from;
            to++;
            n++;
        }
    }
    return n;
}

// Контейнером виступає вбудований контейнер типу масиву int[]
int main()
{
    SetConsoleOutputCP(1251); // для коректного відображення кирилиці

    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int* a = new int[size];
    int* b = new int[size]; // Результуючий масив

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    // Видалення елемента за значенням
    int value;
    cout << "Введіть значення елемента, який потрібно видалити: ";
    cin >> value;

    int newSize1 = erase(a, a + size, b, value);
    cout << "Масив після видалення елемента зі значенням " << value << ": ";
    for (int i = 0; i < newSize1; i++)
        cout << b[i] << ' ';
    cout << endl;

    // Видалення від'ємних елементів
    Predicate<int>* neg = new Negative<int>();
    int newSize2 = erase_if(a, a + size, b, *neg);

    cout << "Масив після видалення від'ємних елементів: ";
    for (int i = 0; i < newSize2; i++)
        cout << b[i] << ' ';
    cout << endl;

    delete[] a;
    delete[] b;
    delete neg;

    return 0;
}