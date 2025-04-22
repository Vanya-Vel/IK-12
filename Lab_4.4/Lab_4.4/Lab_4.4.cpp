// Lab_04_4.cpp
// < Величко Іван >
// Лабораторна робота № 4.4
// Абстрактні класи
// Варіант 0.4

#include <iostream>
#include "Dollar.h"
#include "Euro.h"
using namespace std;

int main() {
    int dollar, euro;

    cout << "enter the amount to exchange dollars ";
    cin >> dollar;

    Currency* currency = new Dollar();
    currency->ExchangeDisplay(dollar);

    cout << "enter the amount to exchange euros ";
    cin >> euro;

    currency = new Euro();
    currency->ExchangeDisplay(euro);

    delete currency; // Очищаємо пам'ять
    return 0;
}
