#include "Point.h"
#include <cmath>
#include <iostream>
#include <string>
#include <sstream> // п≥дключаЇмо б≥бл≥отеку, €ка описуЇ л≥терн≥ потоки

using namespace std;

// ‘ункц≥€ дл€ зм≥щенн€ точки по ос≥ X
void Point::moveX(int stepX)
{
	x += stepX;
}

// ‘ункц≥€ дл€ зм≥щенн€ точки по ос≥ Y
void Point::moveY(int stepY)
{
	y += stepY;
}

// ‘ункц≥€ дл€ обчисленн€ в≥дстан≥ м≥ж двома точками
double Point::distanceFromXtoY(const Point& other) const
{
	// ¬икористовуЇмо формулу в≥дстан≥ м≥ж двома точками в евкл≥дов≥й систем≥ координат
	return sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
}

// ≤н≥ц≥ал≥зац≥€ точки з заданими координатами
bool Point::Init(int CoorX, int CoorY)
{
	this->x = CoorX;  // ѕрисвоюЇмо координату x
	this->y = CoorY;  // ѕрисвоюЇмо координату y
	return true;
}

// ‘ункц≥€ дл€ в≥дображенн€ координат точки
void Point::Display() const
{
	cout << " coordinates = (" << x << "; " << y << ")" << endl;
}

// ‘ункц≥€ дл€ зчитуванн€ координат точки з консол≥
void Point::Read()
{
	int CoorX, CoorY;
	cout << "Enter starting coordinates (x, y): " << endl;
	cout << "x "; cin >> CoorX;  // «читуЇмо x
	cout << "y "; cin >> CoorY;  // «читуЇмо y
	Init(CoorX, CoorY);  // ≤н≥ц≥ал≥зуЇмо точку з отриманими координатами
}

// ‘ункц≥€ дл€ переведенн€ числа в текстовий формат
string Point::ToNumeral(int number) const {
    // ћасиви дл€ перетворенн€ чисел у в≥дпов≥дн≥ текстов≥ значенн€
    const char* _centuries[] = { "", "sto", "dvisti", "trysta", "4onyrysta", "pТjatsot", "6istsot", "simsot", "visimsot", "devТjatsot", "tysia4a abo >" };
    const char* _decades[] = { "", "", "dvadciatТ", "trydciatТ", "sorok", "pТjatdesiat", "6istdesiat", "simdesiat", "visimdesiat", "devТjanosto" };
    const char* _digits[] = { "", "odyn", "dva", "try", "4otyry", "pТjatТ", "6istТ", "sim", "visim", "devТjatТ", "desiatТ", "odynadciadТ", "dvanadciadТ", "trynadciadТ", "4otyrnadciadТ", "pТjatnadciadТ", "6istnadciadТ", "simnadciadТ", "visimnadciadТ", "devТjatnadciadТ" };

    if (number == 0) return "нуль";

    string result = "";  // —творюЇмо зм≥нну дл€ збер≥ганн€ результату
    if (number >= 100) {
        result += _centuries[number / 100] + string(" ");
        number %= 100;  // ќновлюЇмо число п≥сл€ обробки сотень
    }
    if (number >= 20) {
        result += _decades[number / 10] + string(" ");
        number %= 10;  // ќновлюЇмо число п≥сл€ обробки дес€тк≥в
    }
    if (number > 0) {
        result += _digits[number] + string(" ");
    }
    if (number < 0) {
        return "error";  // якщо число в≥д'Їмне, повертаЇмо "error"
    }

    return result;
}

// ‘ункц≥€ дл€ перетворенн€ в≥дстан≥ м≥ж двома точками в текстовий формат
string Point::toString(const Point& other) const {
    double dist = distanceFromXtoY(other);  // ќбчислюЇмо в≥дстань
    int roundedDist = static_cast<int>(round(dist));  // ќкруглюЇмо в≥дстань
    return ToNumeral(roundedDist);  // ѕеретворюЇмо округлену в≥дстань в текстовий формат
}

// ‘ункц≥€ дл€ зм≥щенн€ точки на задану к≥льк≥сть одиниць по ос€х X та Y
void Point::displacement()
{
	int stepX, stepY;
	cout << "Enter how much to move on X and Y: " << endl;
	cout << "x "; cin >> stepX;
	cout << "y "; cin >> stepY;

	moveX(stepX);  // «м≥щуЇмо точку по ос≥ X
	moveY(stepY);  // «м≥щуЇмо точку по ос≥ Y
}
