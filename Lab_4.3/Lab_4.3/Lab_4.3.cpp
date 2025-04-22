// Lab_04_3.cpp
// < Величко Іван >
// Лабораторна робота № 4.3
// Віртуальні функції для класів з масивом
// Варіант 0.4

#include <iostream>
#include <typeinfo>
#include "Money.h"
#include "BitString.h"
#include "windows.h"

int main() {
    SetConsoleCP(1251);       // Встановити CP1251 для вводу
    SetConsoleOutputCP(1251); // Встановити CP1251 для виводу

    // === Поліморфізм з Money ===
    Array* arr1 = new Money(5, 1); // 11111
    Array* arr2 = new Money(5, 2); // 22222

    cout << "Тип arr1: " << typeid(*arr1).name() << endl;
    cout << "Тип arr2: " << typeid(*arr2).name() << endl;

    cout << "\n--- ДО додавання Money ---" << endl;
    arr1->print();
    arr2->print();

    arr1->add(*arr2); // 11111 + 22222 = 33333

    cout << "\n--- ПІСЛЯ додавання Money ---" << endl;
    arr1->print();

    delete arr1;
    delete arr2;

    // === BitString тести ===
    BitString bs1(8);  // 00000000
    BitString bs2(8);  // 00000000

    // Встановимо значення вручну:
    // bs1 = 10101010
    // bs2 = 11001100
    bs1[0] = 0; bs1[1] = 1; bs1[2] = 0; bs1[3] = 1;
    bs1[4] = 0; bs1[5] = 1; bs1[6] = 0; bs1[7] = 1;

    bs2[0] = 0; bs2[1] = 0; bs2[2] = 1; bs2[3] = 1;
    bs2[4] = 0; bs2[5] = 0; bs2[6] = 1; bs2[7] = 1;

    cout << "\n=== BitString: початкові значення ===" << endl;
    cout << "bs1: "; bs1.print();
    cout << "bs2: "; bs2.print();

    // AND
    BitString and_result = bs1;
    and_result.bitwise_and(bs2);
    cout << "\nРезультат AND: ";
    and_result.print();

    // OR
    BitString or_result = bs1;
    or_result.bitwise_or(bs2);
    cout << "Результат OR: ";
    or_result.print();

    // XOR
    BitString xor_result = bs1;
    xor_result.bitwise_xor(bs2);
    cout << "Результат XOR: ";
    xor_result.print();

    // NOT
    BitString not_result = bs1;
    not_result.bitwise_not();
    cout << "Результат NOT (для bs1): ";
    not_result.print();

    // Shift left на 2 біти
    BitString left_shift = bs1;
    left_shift.shift_left(2);
    cout << "\nЗсув вліво на 2 біти (для bs1): ";
    left_shift.print();

    // Shift right на 2 біти
    BitString right_shift = bs1;
    right_shift.shift_right(2);
    cout << "Зсув вправо на 2 біти (для bs1): ";
    right_shift.print();

    return 0;
}
