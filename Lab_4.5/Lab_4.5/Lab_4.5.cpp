// Lab_04_5.cpp
// < Величко Іван >
// Лабораторна робота № 4.5
// Інтерфейси (до 4.4) 
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
    cout << "Object type: " << typeid(*currency).name() << endl;
    currency->ExchangeDisplay(dollar);

    cout << "enter the amount to exchange euros ";
    cin >> euro;

    currency = new Euro();
    cout << "Object type: " << typeid(*currency).name() << endl;
    currency->ExchangeDisplay(euro);

    delete currency; // Очищаємо пам'ять
    return 0;
}
