#pragma once
#include <string>
#include "Pair.h"
using namespace std;

class Rectangle
{
private:
	Pair sides;  // зберігаються сторони прямокутника

public:
	// Отримання пари сторін прямокутника
	Pair getPair() const { return sides; }

	// Встановлення нових значень сторін
	void setPair(const Pair& sides) { this->sides = sides; }

	// Обчислення периметра прямокутника
	int getPerimeter() const { return 2 * (sides.getFirst() + sides.getSecond()); }

	// Обчислення площі прямокутника
	int getArea() const { return sides.multiply(); }

	// Ініціалізація сторін прямокутника
	void Init(const Pair& sides);

	// Виведення інформації про прямокутник
	void Display() const;

	// Читання значень сторін прямокутника
	void Read();
};
