#include "Point.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream> // ��������� ��������, ��� ����� ����� ������

using namespace std;

// ������� ��� ������� ����� �� �� X
void Point::moveX(int stepX)
{
	x += stepX;
}

// ������� ��� ������� ����� �� �� Y
void Point::moveY(int stepY)
{
	y += stepY;
}

// ������� ��� ���������� ������ �� ����� �������
double Point::distanceFromXtoY(const Point& other) const
{
	// ������������� ������� ������ �� ����� ������� � �������� ������ ���������
	return sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
}

// ����������� ����� � �������� ������������
bool Point::Init(int CoorX, int CoorY)
{
	this->x = CoorX;  // ���������� ���������� x
	this->y = CoorY;  // ���������� ���������� y
	return true;
}

// ������� ��� ����������� ��������� �����
void Point::Display() const
{
	cout << " coordinates = (" << x << "; " << y << ")" << endl;
}

// ������� ��� ���������� ��������� ����� � ������
void Point::Read()
{
	int CoorX, CoorY;
	cout << "Enter starting coordinates (x, y): " << endl;
	cout << "x "; cin >> CoorX;  // ������� x
	cout << "y "; cin >> CoorY;  // ������� y
	Init(CoorX, CoorY);  // ���������� ����� � ���������� ������������
}

// ������� ��� ����������� ����� � ��������� ������
string Point::ToNumeral(int number) const {
    // ������ ��� ������������ ����� � ������� ������� ��������
    const char* _centuries[] = { "", "sto", "dvisti", "trysta", "4onyrysta", "p�jatsot", "6istsot", "simsot", "visimsot", "dev�jatsot", "tysia4a abo >" };
    const char* _decades[] = { "", "", "dvadciat�", "trydciat�", "sorok", "p�jatdesiat", "6istdesiat", "simdesiat", "visimdesiat", "dev�janosto" };
    const char* _digits[] = { "", "odyn", "dva", "try", "4otyry", "p�jat�", "6ist�", "sim", "visim", "dev�jat�", "desiat�", "odynadciad�", "dvanadciad�", "trynadciad�", "4otyrnadciad�", "p�jatnadciad�", "6istnadciad�", "simnadciad�", "visimnadciad�", "dev�jatnadciad�" };

    if (number == 0) return "����";

    string result = "";  // ��������� ����� ��� ��������� ����������
    if (number >= 100) {
        result += _centuries[number / 100] + string(" ");
        number %= 100;  // ��������� ����� ���� ������� ������
    }
    if (number >= 20) {
        result += _decades[number / 10] + string(" ");
        number %= 10;  // ��������� ����� ���� ������� �������
    }
    if (number > 0) {
        result += _digits[number] + string(" ");
    }
    if (number < 0) {
        return "error";  // ���� ����� ��'����, ��������� "error"
    }

    return result;
}

// ������� ��� ������������ ������ �� ����� ������� � ��������� ������
string Point::toString(const Point& other) const {
    double dist = distanceFromXtoY(other);  // ���������� �������
    int roundedDist = static_cast<int>(round(dist));  // ���������� �������
    return ToNumeral(roundedDist);  // ������������ ��������� ������� � ��������� ������
}

// ������� ��� ������� ����� �� ������ ������� ������� �� ���� X �� Y
void Point::displacement()
{
	int stepX, stepY;
	cout << "Enter how much to move on X and Y: " << endl;
	cout << "x "; cin >> stepX;
	cout << "y "; cin >> stepY;

	moveX(stepX);  // ������ ����� �� �� X
	moveY(stepY);  // ������ ����� �� �� Y
}
