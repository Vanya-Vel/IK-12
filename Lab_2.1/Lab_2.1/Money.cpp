#include "Money.h"
#include <iostream>
#include <sstream>

using namespace std;

Money::Money()		//конструтор за замовчуванням
{
	first = 0;		// ініціалізуємо номінал на 0
	second = 0;		// ініціалізуємо кількість купюр на 0
}

Money::Money(unsigned int Denom, unsigned int NumOfDenom)	// Конструктор з параметрами
{
	// Логіка перевірки допустимих номіналів
	int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
	bool isValid = false;

	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)	// перевіряємо чи допустимий номінал
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}
	// Якщо номінал не допустимий, обираємо значення за замовчуванням
	if (!isValid)
	{
		first = 0;
		second = 0;
	}
	else
	{
		first = Denom;		// встановлюємо номінал
		second = (NumOfDenom != 0) ? NumOfDenom : 0;	// перевірка на нульову кількість купюр
	}
}

Money::Money(const Money& d)	// Конструктор копіювання
{
	first = d.first;			// копіюємо номінал
	second = d.second;			// копіюємо кількість купюр
}

Money::~Money()			// Деструктор
{ }

void Money::SetFirst(unsigned int Denom)		// Метод для встановлення номіналу
{
	// Логіка з Init
	int validDenoms[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	bool isValid = false;


	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)	// перевірка на допустимість номіналу
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}
	// Якщо номінал допустимий, встановлюємо значення, в іншому випадку встановлюємо 0
	if (isValid)
		first = Denom;
	else
		first = 0;
}

void Money::SetSecond(unsigned int NumOfDenom)		// Метод для встановлення кількості купюр
{
	second = (NumOfDenom != 0) ? NumOfDenom : 0;	// якщо кількість купюр більше за 0, встановлюємо значення
}

unsigned int Money::GetFirst() const				// Геттер для номіналу
{
	return first;
}
		
unsigned int Money::GetSecond() const				// Геттер для кількості купюр
{
	return second;
}

Money& Money::operator = (const Money& d)			// Оператор присвоєння
{
	if (this != &d) {		// Перевірка на самоприсвоєння
		first = d.first;
		second = d.second;
	}
	return *this;
}

Money::operator string () const		// Перетворення в рядок
{
	stringstream ss;
	ss << " First = " << first << endl;		// Додаємо значення першої частини (номінал)
	ss << " Second = " << second << endl;	// Додаємо значення другої частини (кількість купюр)
	return ss.str();
}

Money& Money::operator ++()		// Префіксне інкрементування (збільшуємо номінал)
{
	first++;
	return *this;
}

Money& Money::operator --()		// Префіксне декрементування (зменшуємо номінал)
{
	first--;
	return *this;
}

Money Money::operator ++(int)	// Постфіксне інкрементування (створюємо копію, потім збільшуємо кількість купюр)
{
	Money t(*this);			// Копіюємо поточний об'єкт
	second++;				// Збільшуємо кількість купюр
	return t;				// Повертаємо копію до зміни
}

Money Money::operator --(int)	// Постфіксне декрементування (створюємо копію, потім зменшуємо кількість купюр)
{
	Money t(*this);			// Копіюємо поточний об'єкт
	second--;				// Зменшуємо кількість купюр
	return t;				// Повертаємо копію до зміни
}

Money operator * (const Money& d, unsigned int multiplier) {	// Оператор множення
	return Money(d.first, d.second * multiplier);				// Повертаємо новий об'єкт Money з помноженою кількістю купюр
}

ostream& operator << (ostream& out, const Money& d)				// Оператор виведення
{
	// Логіка з Display
	out << "first (denominations) = " << d.first << " second (number of denominations) = " << d.second << endl;
	out << "Сума = " << d.first * d.second << endl;		// Обчислюємо і виводимо загальну суму
	return out;
}

istream& operator >> (istream& in, Money& d)		// Оператор введення
{
	// Логіка з Read
	int Denom, NumOfDenom;
	int validDenoms[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
	bool isValid = false;

	// Введення першого значення (номіналу)
	do {
		cout << "first = ";
		cin >> Denom;
		if (Denom <= 0)
		{
			cout << "Помилка! Значення має бути додатнім. Спробуйте ще раз.\n";
		}
		for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)
		{

			if (Denom == validDenoms[i])
			{
				isValid = true;
				break;
			}
						
		}
		if (!isValid && Denom > 0) {
			cout << "Помилка! Неправильне значення номіналу. Спробуйте ще раз.\n";
			break;
		}
		
	} while (!isValid);

	d.first = Denom;

	// Введення другого значення (кількості купюр)
	do {
		cout << "second = ";
		cin >> NumOfDenom;
		if (NumOfDenom <= 0) 
		{
			cout << "Помилка! Значення має бути додатнім. Спробуйте ще раз.\n";
		}
	} while (NumOfDenom <= 0);

	d.second = NumOfDenom;
	return in;
}