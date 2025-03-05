#include "Money.h"
#include <iostream>
using namespace std;

// ѕерев≥рка коректност≥ ном≥налу та к≥лькост≥ купюр
bool Money::Init(int Denom, int NumOfDenom)
{
	int validDenoms[9] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };

	// ѕерев≥рка чи Denom Ї в списку допустимих значень
	bool isValid = false;
	for (int i = 0; i < sizeof(validDenoms) / sizeof(validDenoms[0]); i++)
	{
		if (Denom == validDenoms[i])
		{
			isValid = true;
			break;
		}
	}

	// якщо ном≥нал недопустимий, скидаЇмо значенн€
	if (!isValid)
	{
		first = 0;
		return false;
	}
	else first = Denom;

	// ѕерев≥рка, чи к≥льк≥сть купюр не дор≥внюЇ нулю
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

// ¬ив≥д ном≥налу та к≥лькост≥ купюр
void Money::Display() const
{
	cout << "first (denominations) = " << first << " second (number of denominations) = " << second << endl;
}

// «читуванн€ даних з клав≥атури
void Money::Read()
{
	int Denom, NumOfDenom;

	// ¬водимо ном≥нал поки в≥н не стане допустимим
	do {
		cout << "first = ";
		cin >> Denom;
	} while (!Init(Denom, 1));

	// ¬водимо к≥льк≥сть купюр поки вона не буде допустимою
	do {
		cout << "second = ";
		cin >> NumOfDenom;
	} while (!Init(Denom, NumOfDenom));
}
