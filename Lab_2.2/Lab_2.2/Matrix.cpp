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

	// �������� ���'�� ��� ���� �������
	m = new int* [R];
	for (int i = 0; i < R; i++) 
	{
		m[i] = new int[C];
		for (int j = 0; j < C; j++) 
		{
			m[i][j] = other.m[i][j]; // ������� ��������
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < R; i++)
	{
		if (m[i] != nullptr)
			delete[] m[i]; // ��������� ����� �������
	}
		// ��������� ������ ��������� �� ����� �������
		if (m != nullptr)
			delete[] m;
}

Matrix Matrix::operator + (const Matrix& other) {
	// �������� �� ���������� ������ ������� ��� �������� ���������
	if (this->R != other.R || this->C != other.C) {
		cout << "������ ������� �� ���������� ��� ���������!" << endl;
		return Matrix(0, 0); // ��������� ������� �������
	}

	// ��������� ���� �������, �� ����� ������� ���� ����������� ���������
	Matrix result(this->R, this->C);

	// ������ ������� ��������
	for (int i = 0; i < this->R; i++) 
	{
		for (int j = 0; j < this->C; j++) 
		{
			result.m[i][j] = this->m[i][j] + other.m[i][j];
		}
	}

	return result; // ��������� ���������
}

Matrix Matrix::operator - (const Matrix& other) {
	// �������� �� ���������� ������ ������� ��� �������� ��������
	if (this->R != other.R || this->C != other.C) {
		cout << "������ ������� �� ���������� ��� ��������!" << endl;
		return Matrix(0, 0); // ��������� ������� �������
	}

	// ��������� ���� �������, �� ����� ������� ���� ����������� ��������
	Matrix result(this->R, this->C);

	// ������ ������� ��������
	for (int i = 0; i < this->R; i++)
	{
		for (int j = 0; j < this->C; j++)
		{
			result.m[i][j] = this->m[i][j] - other.m[i][j];
		}
	}

	return result; // ��������� ���������
}

Matrix Matrix::operator * (const Matrix& other) {
	// ��������, �� ������� �������� ����� ������� ������� ������� ����� ����� �������
	if (this->C != other.R) {
		cout << "�������� ���������: ������� �������� ����� ������� ������� ���������� ������� ����� ����� �������!" << endl;
		return Matrix(0, 0);  // ��������� ������� �������
	}

	// ��������� ���� ������� ��� ���������� � �������� R1 x C2
	Matrix result(this->R, other.C);

	// �������� ��������
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < other.C; j++) {
			result.m[i][j] = 0;  // ����������� �������� ����������
			for (int k = 0; k < this->C; k++) {
				result.m[i][j] += this->m[i][k] * other.m[k][j];
			}
		}
	}
	return result;  // ��������� ��������� ��������
}

Matrix& Matrix::operator = (const Matrix& other)
{
	if (this != &other) {  // �������� �� �������������
		// ���� �������� ��'��� ��� ������ ���, ��������� ���'���
		for (int i = 0; i < R; i++) {
			delete[] m[i]; // ��������� ����� �����
		}
		delete[] m; // ��������� ��� ����� �����

		// ������� ������
		R = other.R;
		C = other.C;

		// �������� ���� ���'��� ��� �������
		m = new int* [R];
		for (int i = 0; i < R; i++) {
			m[i] = new int[C];
		}

		// ������� �������� � ���� �������
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				m[i][j] = other.m[i][j];
			}
		}
	}
	return *this;  // ��������� �������� ��'��� ��� ���������� �������
}

Matrix& Matrix::operator += (const Matrix& other) {
	// �������� �� ���������� ������ ������� ��� �������� ���������
	if (this->R != other.R || this->C != other.C) {
		cout << "������ ������� �� ���������� ��� ���������!" << endl;
		return *this;  // ��������� �������� ��'��� ��� ���
	}

	// ������ ������� ��������
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < this->C; j++) {
			this->m[i][j] += other.m[i][j];  // ������ �������� ������� � ����� �������
		}
	}

	return *this;  // ��������� �������� ��'��� ���� ���������
}

Matrix& Matrix::operator -= (const Matrix& other)
{
	// �������� �� ���������� ������ ������� ��� �������� ��������
	if (this->R != other.R || this->C != other.C) {
		cout << "������ ������� �� ���������� ��� ��������!" << endl;
		return *this;  // ��������� �������� ��'��� ��� ���
	}

	// ������ ������� ��������
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < this->C; j++) {
			this->m[i][j] -= other.m[i][j];  // ³������ �������� ������� � ����� �������
		}
	}

	return *this; // ��������� �������� ��'��� ���� ��������
}

Matrix& Matrix::operator *= (const Matrix& other)
{
	// ��������, �� ������� �������� ����� ������� ������� ������� ����� ����� �������
	if (this->C != other.R) {
		cout << "�������� ���������: ������� �������� ����� ������� ������� ���������� ������� ����� ����� �������!" << endl;
		return *this;  // ��������� ������� ������� ��� ���
	}

	// ��������� ���� ������� ��� ���������� � �������� R1 x C2
	Matrix result(this->R, other.C);

	// �������� ��������
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < other.C; j++) {
			result.m[i][j] = 0;  // ����������� �������� ����������
			for (int k = 0; k < this->C; k++) {
				result.m[i][j] += this->m[i][k] * other.m[k][j];  // ������ ������� ��������
			}
		}
	}

	// ������� ��������� � �������� ��'���
	this->R = result.R;
	this->C = result.C;
	for (int i = 0; i < this->R; i++) {
		for (int j = 0; j < this->C; j++) {
			this->m[i][j] = result.m[i][j];
		}
	}

	return *this;  // ��������� �������� ��'��� ���� ��������
}

ostream& operator << (ostream& out, const Matrix& other) {
	// ��������� ������� ����� � ��������
	out << "������� [" << other.R << ";" << other.C << "]:" << endl;

	// ��������� �������� �������
	for (int i = 0; i < other.R; i++) {
		for (int j = 0; j < other.C; j++) {
			out << other.m[i][j] << " ";  // ��������� ��������
		}
		out << endl;  // ������� �� ����� ����� ���� ��������� ������ ����� �������
	}

	return out;
}

istream& operator >> (istream& in, Matrix& other) {
	int row, col;
	bool isValid = false;

	// �������� ������� �����
	do {
		cout << "�����: ";
		in >> row;
		if (row <= 0) {  // �������� �� ������ ��������
			cout << "�������! �������� �� ���� �������. ��������� �� ���.\n";
			isValid = false;
		}
		else {
			isValid = true;
		}
	} while (!isValid);

	other.R = row;  // ������������ ������� �����

	// �������� ������� ��������
	do {
		cout << "�������: ";
		in >> col;
		if (col <= 0) {  // �������� �� ������ ��������
			cout << "�������! �������� �� ���� �������. ��������� �� ���.\n";
			isValid = false;
		}
		else {
			isValid = true;
		}
	} while (!isValid);

	other.C = col;  // ������������ ������� ��������

	// ��������� �������� ���'�� ��� �������
	other.m = new int* [other.R];
	for (int i = 0; i < other.R; i++) {
		other.m[i] = new int[other.C];
	}

	// �������� �������� �������
	cout << "������ �������� �������:\n";
	for (int i = 0; i < other.R; i++) {
		for (int j = 0; j < other.C; j++) {
			in >> other.m[i][j];
		}
	}

	return in;  // ��������� ����
}
