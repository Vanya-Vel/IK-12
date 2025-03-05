#include "Pair.h"
#include <iostream>
using namespace std;

void Pair::Init(int first, int second)
{
	setFirst(first);  // Встановлення першого елемента пари
	setSecond(second);  // Встановлення другого елемента пари
}

void Pair::Display() const
{
	cout << endl;
	cout << "First number = " << first << endl;  // Виведення першого елемента
	cout << "Second number = " << second << endl;  // Виведення другого елемента
}

void Pair::Read()
{
	int first, second;
	cout << endl;
	cout << "First = ? "; cin >> first;  // Введення першого елемента
	cout << "Second = ? "; cin >> second;  // Введення другого елемента
	Init(first, second);  // Ініціалізація пари введеними значеннями
}
