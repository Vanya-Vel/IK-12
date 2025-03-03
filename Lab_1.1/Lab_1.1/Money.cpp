#include "Money.h"
#include <iostream>
using namespace std;

// Встановлення номіналу
void Money::SetFirst(int value)
{
	first = value;
}

// Встановлення кількості купюр
void Money::SetSecond(unsigned int value)
{
	second = value;
}

// Перевірка коректності номіналу та кількості купюр
bool Money::Init(int Denom, int NumOfDenom)
{
	int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };

	// Перевірка чи Denom є в списку допустимих значень
	bool isValid = false;
	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}

	// Якщо номінал недопустимий, скидаємо значення
	if (!isValid)
	{
		first = 0;
		return false;
	}
	else first = Denom;

	// Перевірка, чи кількість купюр не дорівнює нулю
	if (NumOfDenom != 0)
	{
		second = NumOfDenom;
		return true;
	}
	else
	{
		second = 0;
		return false;
	}
}

// Вивід номіналу та кількості купюр
void Money::Display() const
{
	cout << "first (denominations) = " << first << " second (number of denominations) = " << second << endl;
}

// Зчитування даних з клавіатури
void Money::Read()
{
	int Denom, NumOfDenom;

	// Вводимо номінал поки він не стане допустимим
	do {
		cout << "first = ";
		cin >> Denom;
	} while (!Init(Denom, 1));

	// Вводимо кількість купюр поки вона не буде допустимою
	do {
		cout << "second = ";
		cin >> NumOfDenom;
	} while (!Init(Denom, NumOfDenom));
}

// Обчислення загальної суми грошей
int Money::Summa()
{
	return (first * second);
}
