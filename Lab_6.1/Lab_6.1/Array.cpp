#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <exception>
using namespace std;

// Конструктор з розміром
Array::Array(const Array::size_type& n) throw(bad_alloc, invalid_argument)
{
    First = 0;
    Count = Size = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0;
}

// Конструктор з діапазоном ітераторів
Array::Array(const iterator first, const iterator last) throw(bad_alloc, invalid_argument)
{
    First = 0;
    if (first <= last) {
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("Неправильний діапазон ітераторів!");
}

// Конструктор з першого і останнього індексу
Array::Array(const size_type first, const size_type last) throw(bad_alloc, invalid_argument)
{
    if (first <= last) {
        First = first;
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("Неправильний діапазон індексів!");
}

// Конструктор копіювання
Array::Array(const Array& t) throw(bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
    for (UINT i = 0; i < Size; ++i)
        elems[i] = t.elems[i];
}

// Оператор присвоєння
Array& Array::operator=(const Array& t)
{
    Array tmp(t);
    swap(tmp);
    return *this;
}

// Деструктор
Array::~Array()
{
    delete[] elems;
    elems = 0;
}

// Додавання елемента в кінець
void Array::push_back(const value_type& v)
{
    if (Count == Size)
        resize(Size * 2);
    elems[Count++] = v;
}

// Зменшення кількості елементів (видалення останнього)
void Array::pop_back()
{
    if (Count > 0)
        --Count;
    else
        throw underflow_error("Масив порожній!");
}

// Доступ до елементу за індексом
Array::reference Array::operator[](size_type index) throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Індекс поза діапазоном!");
}

// Константний доступ до елемента
Array::const_reference Array::operator[](size_type index) const throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Індекс поза діапазоном!");
}

// Зміна розміру масиву
void Array::resize(size_type newsize) throw(bad_alloc)
{
    if (newsize > capacity())
    {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

// Обмін масивами
void Array::swap(Array& other)
{
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
    std::swap(Count, other.Count);
    std::swap(First, other.First);
}

// Отримати місткість
Array::size_type Array::capacity() const
{
    return Size;
}

// Отримати поточний розмір
Array::size_type Array::size() const
{
    return Count;
}

// Перевірка на пустоту
bool Array::empty() const
{
    return Count == 0;
}

// Введення масиву
istream& operator>>(istream& in, Array& tmp)
{
    for (size_t i = 0; i < tmp.Count; ++i)
        in >> tmp.elems[i];
    return in;
}

// Виведення масиву
ostream& operator<<(ostream& out, const Array& tmp)
{
    for (size_t j = 0; j < tmp.Count; j++)
        out << tmp[j] << " ";
    out << endl;
    return out;
}

// Заповнення масиву певним значенням
void Array::assign(const value_type& v)
{
    for (size_type i = 0; i < Size; ++i)
        elems[i] = v;
}

// Реалізація функції обробки масиву
Array Array::MultiplyByMinimum(const Array::value_type* inputArray, int size)
{
    if (size <= 0)
        throw invalid_argument("Розмір масиву повинен бути додатнім!");

    // Створення об'єкта Array
    Array result(size);

    // Копіюємо вхідні дані
    for (int i = 0; i < size; ++i)
        result[i] = inputArray[i];

    // Пошук мінімального елемента в масиві
    double minVal = result[0];  // Ініціалізація мінімального елемента

    for (int i = 1; i < size; ++i)  // Починаємо з другого елемента, оскільки перший вже взятий
    {
        if (result[i] < minVal)
            minVal = result[i];  // Знаходимо мінімальний елемент
    }

    cout << "Мінімальний елемент: " << minVal << endl;  // Вивести мінімальний елемент для перевірки

    // Множимо всі елементи на мінімальний елемент
    for (int i = 0; i < size; ++i)
        result[i] *= minVal;

    return result;
}

