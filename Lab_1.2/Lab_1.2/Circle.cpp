#include "Circle.h"
#include <iostream>

using namespace std;


bool Circle::Init(int x, int y, double radius)
{
    if (radius > 0) // ѕерев≥р€Їмо, чи рад≥ус б≥льше за нуль
    {
        this->x = x;  // якщо так, ≥н≥ц≥ал≥зуЇмо координати ≥ рад≥ус
        this->y = y;
        this->radius = radius;
        return true; // ѕовертаЇмо true, €кщо ≥н≥ц≥ал≥зац≥€ усп≥шна
    }
    else
    {
        this->x = x; // якщо рад≥ус некоректний (менший або р≥вний нулю), ≥н≥ц≥ал≥зуЇмо координати, але ставимо рад≥ус р≥вним 0
        this->y = y;
        this->radius = 0;  // ћ≥н≥мально допустиме значенн€ рад≥усу
        return false; // ѕовертаЇмо false, €кщо ≥н≥ц≥ал≥зац≥€ не вдалас€
    }
}

void Circle::Display() const
{
    cout << " centre coordinates = (" << x << "; " << y << ")" << endl; // ¬иведенн€ координат центру кола
    cout << " radius = " << radius << endl; // ¬иведенн€ рад≥усу кола
}

void Circle::Read()
{
    int x, y;
    double radius;
    do {
        cout << " Coordinate x = ? "; cin >> x; // «читуЇмо x-координату
        cout << " coordinate y = ? "; cin >> y; // «читуЇмо y-координату
        cout << " Radius = ? "; cin >> radius; // «читуЇмо рад≥ус
    } while (!Init(x, y, radius)); // якщо ≥н≥ц≥ал≥зац≥€ не вдалас€ (рад≥ус <= 0), запитуЇмо введенн€ знову
}
