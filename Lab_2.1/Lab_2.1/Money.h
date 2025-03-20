#pragma once  // Захист від багаторазового включення заголовкового файлу

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Money
{
private:
    unsigned int first;  // Номінал купюри
    unsigned int second; // Кількість купюр

public:
    Money();                                 // конструктор без аргументів
    Money(unsigned int, unsigned int);       // конструктор ініціалізації
    Money(const Money&);                     // конструктор копіювання
    ~Money();

    void SetFirst(unsigned int);             // Встановити номінал
    void SetSecond(unsigned int);            // Встановити кількість купюр
    unsigned int GetFirst() const { return first; }          // Отримати номінал
    unsigned int GetSecond() const { return second; }          // Отримати кількість купюр

    Money& operator = (const Money&);        // присвоєння
    operator string() const;                 // приведення до рядка

    Money& operator ++();                    // префіксний інкремент
    Money& operator --();                    // префіксний декремент
    Money operator ++(int);                  // постфіксний інкремент
    Money operator --(int);                  // постфіксний декремент

    friend Money operator * (const Money&, unsigned int);  // Обчислення загальної суми грошей

    friend ostream& operator << (ostream&, const Money&);    // виведення
    friend istream& operator >> (istream&, Money&);           // введення
};

