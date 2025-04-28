#include "Array.h"
#include <iostream>
#include <ctime>
#include "windows.h"
using namespace std;

typedef Array::value_type* TArray;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "n = ";
	cin >> n;

	if (n <= 0)
	{
		cerr << "Розмір масиву повинен бути додатнім!" << endl;
		return 1;
	}

	TArray a = new Array::value_type[n];

	srand((unsigned)time(NULL));
	Array::value_type A = -50;
	Array::value_type B = 50;

	for (int i = 0; i < n; ++i)
		a[i] = A + rand() % (int(B - A + 1));

	cout << "Початковий масив: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	try
	{
		Array result = Array::MultiplyByMinimum(a, n);

		cout << "Модифікований масив: " << endl;
		cout << result;
	}
	catch (const exception& e)
	{
		cerr << "Помилка: " << e.what() << endl;
	}

	delete[] a;
	return 0;
}
