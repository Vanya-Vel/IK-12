#pragma once
#include "AccessMethodology.h"
using namespace std;

// Клас для арифметичних операцій з точками
class ArithmeticOperations : public AccessMethodology {
public:
    // Префіксний інкремент
    ArithmeticOperations& operator ++();     // Префіксний інкремент
    // Префіксний декремент
    ArithmeticOperations& operator --();     // Префіксний декремент
    // Постфіксний інкремент
    ArithmeticOperations operator ++(int);   // Постфіксний інкремент
    // Постфіксний декремент
    ArithmeticOperations operator --(int);   // Постфіксний декремент
    // Операція додавання
    ArithmeticOperations operator + (const ArithmeticOperations&);        // Операція додавання точок
    // Операція присвоєння
    ArithmeticOperations& operator = (const ArithmeticOperations&);       // Операція присвоєння

    // Додаткові операції, специфічні для ArithmeticOperations:
    // Конструктор за умовчанням
    ArithmeticOperations() : AccessMethodology() {}
    // Конструктор з параметрами
    ArithmeticOperations(int x, int y) : AccessMethodology(x, y) {}
    // Конструктор копіювання
    ArithmeticOperations(const ArithmeticOperations& other) : AccessMethodology(other) {}
};
