#pragma once

#include <string>
using namespace std;

class Pair
{
private:
	int first, second;  // два елементи пари

public:
	// Отримання першого елемента пари
	int getFirst() const { return first; }

	// Встановлення першого елемента пари
	void setFirst(int first) { this->first = first; }

	// Отримання другого елемента пари
	int getSecond() const { return second; }

	// Встановлення другого елемента пари
	void setSecond(int second) { this->second = second; }

	// Обчислення добутку двох елементів пари
	int multiply() const { return first * second; }

	// Ініціалізація пари значеннями
	void Init(int first, int second);

	// Виведення значень пари
	void Display() const;

	// Читання значень пари
	void Read();
};
