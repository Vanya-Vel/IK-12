#include "Matrix.h"
#include <iostream>
#include <sstream>

Matrix::Matrix()
{
	R = C = 1;
	m = new int* [this->R];
	for (int i = 0; i < this->R; i++)
	{
		m[i] = new int[this->C];
		for (int j = 0; j < this->C; j++)
			m[i][j] = 0;
	};
}

Matrix::Matrix(int n)
{
		if (n < 0)
		{
			cout << "error!" << endl;
		}

		if (n == 0)
		{
			cout << "0x0 matrix is not a valid value" << endl;
		}

		if (n > 0)
		{
			R = C = n;
			m = new int* [this->R];
			for (int i = 0; i < this->R; i++)
			{
				m[i] = new int[this->C];
				for (int j = 0; j < this->C; j++)
					m[i][j] = 0;
			}
		}
}

Matrix::Matrix(int row, int col)
{

	this->R = row < 1 ? 1 : row;
	this->C = col < 1 ? 1 : col;

	m = new int* [this->R];
	for (int i = 0; i < this->R; i++)
	{
		m[i] = new int[this->C];
		for (int j = 0; j < this->C; j++)
		{
			m[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other) {
	R = other.R;
	C = other.C;

	// Виділення пам'яті для нової матриці
	m = new int* [R];
	for (int i = 0; i < R; i++) 
	{
		m[i] = new int[C];
		for (int j = 0; j < C; j++) 
		{
			m[i][j] = other.m[i][j]; // Копіюємо значення
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < R; i++)
	{
		if (m[i] != nullptr)
			delete[] m[i]; // видалення рядків матриці
	}
		// видалення масиву вказівників на рядки матриці
		if (m != nullptr)
			delete[] m;
}

Matrix Matrix::operator + (const Matrix& other) {
	// Перевірка на відповідність розмірів матриць для операції додавання
	if (this->R != other.R || this->C != other.C) {
		cout << "Розміри матриць не співпадають для додавання!" << endl;
		return Matrix(0, 0); // Повертаємо порожню матрицю
	}

	// Створення нової матриці, де кожен елемент буде результатом додавання
	Matrix result(this->R, this->C);

	// Додаємо відповідні елементи
	for (int i = 0; i < this->R; i++) 
	{
		for (int j = 0; j < this->C; j++) 
		{
			result.m[i][j] = this->m[i][j] + other.m[i][j];
		}
	}

	return result; // Повертаємо результат
}

Matrix Matrix::operator - (const Matrix& other) {
	// Перевірка на відповідність розмірів матриць для операції віднімання
	if (this->R != other.R || this->C != other.C) {
		cout << "Розміри матриць не співпадають для віднімання!" << endl;
		return Matrix(0, 0); // Повертаємо порожню матрицю
	}

	// Створення нової матриці, де кожен елемент буде результатом віднімання
	Matrix result(this->R, this->C);

	// Додаємо відповідні елементи
	for (int i = 0; i < this->R; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			result.m[i][j] = this->m[i][j] - other.m[i][j];
		}
	}

	return result; // Повертаємо результат
}

Matrix Matrix::operator * (const Matrix& other) {
	// Перевірка, чи кількість стовпців першої матриці дорівнює кількості рядків другої матриці
	if (this->C != other.R) {
		cout << "Множення неможливе: кількість стовпців першої матриці повинна дорівнювати кількості рядків другої матриці!" << endl;
		return Matrix(0, 0);  // Повертаємо порожню матрицю
	}

	// Створюємо нову матрицю для результату з розмірами R1 x C2
	Matrix result(this->R, other.C);

	// Виконуємо множення
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < other.C; j++) {
			result.m[i][j] = 0;  // Ініціалізація елемента результату
			for (int k = 0; k < this->C; k++) {
				result.m[i][j] += this->m[i][k] * other.m[k][j];
			}
		}
	}
	return result;  // Повертаємо результат множення
}

Matrix& Matrix::operator = (const Matrix& other)
{
	if (this != &other) {  // Перевірка на самоприсвоєння
		// Якщо поточний об'єкт вже містить дані, звільняємо пам'ять
		for (int i = 0; i < R; i++) {
			delete[] m[i]; // Видаляємо кожен рядок
		}
		delete[] m; // Видаляємо сам масив рядків

		// Копіюємо розміри
		R = other.R;
		C = other.C;

		// Виділяємо нову пам'ять для матриці
		m = new int* [R];
		for (int i = 0; i < R; i++) {
			m[i] = new int[C];
		}

		// Копіюємо елементи з іншої матриці
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				m[i][j] = other.m[i][j];
			}
		}
	}
	return *this;  // Повертаємо поточний об'єкт для ланцюгових викликів
}

Matrix& Matrix::operator += (const Matrix& other) {
	// Перевірка на відповідність розмірів матриць для операції додавання
	if (this->R != other.R || this->C != other.C) {
		cout << "Розміри матриць не співпадають для додавання!" << endl;
		return *this;  // Повертаємо поточний об'єкт без змін
	}

	// Додаємо відповідні елементи
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < this->C; j++) {
			this->m[i][j] += other.m[i][j];  // Додаємо елементи поточної і другої матриці
		}
	}

	return *this;  // Повертаємо поточний об'єкт після додавання
}

Matrix& Matrix::operator -= (const Matrix& other)
{
	// Перевірка на відповідність розмірів матриць для операції віднімання
	if (this->R != other.R || this->C != other.C) {
		cout << "Розміри матриць не співпадають для віднімання!" << endl;
		return *this;  // Повертаємо поточний об'єкт без змін
	}

	// Додаємо відповідні елементи
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < this->C; j++) {
			this->m[i][j] -= other.m[i][j];  // Віднімаємо елементи поточної і другої матриці
		}
	}

	return *this; // Повертаємо поточний об'єкт після віднімання
}

Matrix& Matrix::operator *= (const Matrix& other)
{
	// Перевірка, чи кількість стовпців першої матриці дорівнює кількості рядків другої матриці
	if (this->C != other.R) {
		cout << "Множення неможливе: кількість стовпців першої матриці повинна дорівнювати кількості рядків другої матриці!" << endl;
		return *this;  // Повертаємо поточну матрицю без змін
	}

	// Створюємо нову матрицю для результату з розмірами R1 x C2
	Matrix result(this->R, other.C);

	// Виконуємо множення
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < other.C; j++) {
			result.m[i][j] = 0;  // Ініціалізація елемента результату
			for (int k = 0; k < this->C; k++) {
				result.m[i][j] += this->m[i][k] * other.m[k][j];  // Додаємо добуток елементів
			}
		}
	}

	// Копіюємо результат у поточний об'єкт
	this->R = result.R;
	this->C = result.C;
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < this->C; j++) {
			this->m[i][j] = result.m[i][j];
		}
	}

	return *this;  // Повертаємо поточний об'єкт після множення
}

ostream& operator << (ostream& out, const Matrix& other) {
	// Виведення кількості рядків і стовпців
	out << "Матриця [" << other.R << ";" << other.C << "]:" << endl;

	// Виведення елементів матриці
	for (int i = 0; i < other.R; i++) {
		for (int j = 0; j < other.C; j++) {
			out << other.m[i][j] << " ";  // Виведення елемента
		}
		out << endl;  // Перехід на новий рядок після виведення одного рядка матриці
	}

	return out;
}

istream& operator >> (istream& in, Matrix& other) {
	int row, col;
	bool isValid = false;

	// Введення кількості рядків
	do {
		cout << "Рядки: ";
		in >> row;
		if (row <= 0) {  // Перевірка на додатнє значення
			cout << "Помилка! Значення має бути додатнім. Спробуйте ще раз.\n";
			isValid = false;
		}
		else {
			isValid = true;
		}
	} while (!isValid);

	other.R = row;  // Встановлюємо кількість рядків

	// Введення кількості стовпців
	do {
		cout << "Стовпці: ";
		in >> col;
		if (col <= 0) {  // Перевірка на додатнє значення
			cout << "Помилка! Значення має бути додатнім. Спробуйте ще раз.\n";
			isValid = false;
		}
		else {
			isValid = true;
		}
	} while (!isValid);

	other.C = col;  // Встановлюємо кількість стовпців

	// Створення динамічної пам'яті для матриці
	other.m = new int* [other.R];
	for (int i = 0; i < other.R; i++) {
		other.m[i] = new int[other.C];
	}

	// Введення елементів матриці
	cout << "Введіть елементи матриці:\n";
	for (int i = 0; i < other.R; i++) {
		for (int j = 0; j < other.C; j++) {
			in >> other.m[i][j];
		}
	}

	return in;  // Повертаємо потік
}
