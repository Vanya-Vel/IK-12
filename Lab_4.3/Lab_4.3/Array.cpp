#include "Array.h"

// Реалізація конструктора
Array::Array(int n, unsigned char value) {
    if (n > MAX_SIZE) {
        cout << "Помилка: перевищено максимальний розмір масиву!" << endl;
        exit(EXIT_FAILURE);
    }
    size = n;
    for (int i = 0; i < size; ++i)
        data[i] = value;
}

// Деструктор
Array::~Array() {}

// Реалізація оператора доступу
unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return data[index];
}

// Реалізація функції додавання
void Array::add(const Array& other) {
    if (size != other.getSize()) {
        cout << "Помилка: масиви різного розміру, додавання неможливе!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i)
        data[i] += other[i];
}

// Реалізація функції виведення
void Array::print() const {
    for (int i = size - 1; i >= 0; --i)
        cout << int(data[i]);
    cout << endl;
}

// Реалізація функції отримання розміру
int Array::getSize() const {
    return size;
}

// Реалізація функції перевірки діапазону
void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        cout << "Помилка: індекс поза допустимим діапазоном!" << endl;
        exit(EXIT_FAILURE);
    }
}
