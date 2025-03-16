#pragma once
#include <string>
#include <istream>
using namespace std;

class Matrix
{
	int R, C;
	int** m;
public:
	Matrix();                   // ����������� �� ����������
	Matrix(int);				// ����������� � ����� ����������
	Matrix(int, int);			// ����������� � ����� �����������
	Matrix(const Matrix&);      // ����������� ���������
	~Matrix();					// ����������

	int GetR() const { return R; }
	void SetR(int value) { R = value; }
	int GetC() const { return C; }
	void SetC(int value) { C = value; }

	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix& operator = (const Matrix&);
	Matrix& operator += (const Matrix&);
	Matrix& operator -= (const Matrix&);
	Matrix& operator *= (const Matrix&);

	// ������ ��� ������� �� �������� �������
	void SetElement(int row, int col, int value) {
		if (row >= 0 && row < R && col >= 0 && col < C) {
			m[row][col] = value;
		}
	}

	int GetElement(int row, int col) const {
		if (row >= 0 && row < R && col >= 0 && col < C) {
			return m[row][col];
		}
		return -1;  // ���� ������� �������� �� ���
	}

	friend ostream& operator << (ostream&, const Matrix&);
	friend istream& operator >> (istream&, Matrix&);
};


