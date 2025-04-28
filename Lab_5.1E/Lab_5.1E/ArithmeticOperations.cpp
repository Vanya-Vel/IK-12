#include "ArithmeticOperations.h"

// Префіксний інкремент
ArithmeticOperations& ArithmeticOperations::operator ++() {
    ++x;  // Збільшуємо x
    return *this;
}

// Префіксний декремент
ArithmeticOperations& ArithmeticOperations::operator --() {
    --y;  // Зменшуємо y
    return *this;
}

// Постфіксний інкремент
ArithmeticOperations ArithmeticOperations::operator ++(int) {
    ArithmeticOperations temp(*this);  // Зберігаємо поточний стан
    x++;  // Збільшуємо x
    return temp;
}

// Постфіксний декремент
ArithmeticOperations ArithmeticOperations::operator --(int) {
    ArithmeticOperations temp(*this);  // Зберігаємо поточний стан
    --y;  // Зменшуємо y
    return temp;
}

// Операція додавання
ArithmeticOperations ArithmeticOperations::operator + (const ArithmeticOperations& other) {
    return ArithmeticOperations(x + other.x, y + other.y);  // Додаємо відповідні координати
}

// Операція присвоєння
ArithmeticOperations& ArithmeticOperations::operator = (const ArithmeticOperations& other) {
    if (this != &other) {  // Перевірка на самоприсвоєння
        x = other.x;
        y = other.y;
    }
    return *this;
}
