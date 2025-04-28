#include "pArithmeticOperations.h"

// Оператор префіксного інкременту
pArithmeticOperations& pArithmeticOperations::operator++() {
    if (!Exception()) {
        // Якщо Exception() повертає false, пропускаємо інкремент
        cout << "Skipping increment due to invalid Pair state." << endl;
        return *this;  // Повертаємо без змін
    }
    // Інкремент першого та другого значення
    setFirst(getFirst() + 1);
    setSecond(getSecond() + 1);
    return *this;
}

// Оператор постфіксного інкременту
pArithmeticOperations pArithmeticOperations::operator++(int) {

    if (!Exception()) {
        pArithmeticOperations temp;
        // Якщо Exception() повертає false, пропускаємо інкремент
        cout << "Skipping increment due to invalid Pair state." << endl;
        return *this;  // Повертаємо без змін
    }
    pArithmeticOperations temp;
    // Зберігаємо поточний об'єкт
    temp = *this;
    setFirst(getFirst() + 1);  // Інкремент першого значення
    setSecond(getSecond() + 1); // Інкремент другого значення
    return temp;  // Повертаємо збережений об'єкт
}

// Оператор префіксного декременту
pArithmeticOperations& pArithmeticOperations::operator--() {
    if (!Exception()) {
        // Якщо Exception() повертає false, пропускаємо декремент
        cout << "Skipping decrement due to invalid Pair state." << endl;
        return *this;  // Повертаємо без змін
    }
    // Декремент першого та другого значення
    setFirst(getFirst() - 1);
    setSecond(getSecond() - 1);
    return *this;
}

// Оператор постфіксного декременту
pArithmeticOperations pArithmeticOperations::operator--(int) {

    if (!Exception()) {
        // Якщо Exception() повертає false, пропускаємо декремент
        cout << "Skipping decrement due to invalid Pair state." << endl;
        return *this;  // Повертаємо без змін
    }
    pArithmeticOperations temp;
    // Зберігаємо поточний об'єкт
    temp = *this;
    setFirst(getFirst() - 1);  // Декремент першого значення
    setSecond(getSecond() - 1); // Декремент другого значення
    return temp;  // Повертаємо збережений об'єкт
}
