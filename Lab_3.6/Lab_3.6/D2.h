#pragma once
#include "D1.h"

class D2 : public D1
{
    int d3;

public:
    D2(int x, int y, int z) : D1(x, y, z), d3(z) {}

    ~D2() {}

    void show_D2()
    {
        cout << "class D2:" << endl;
        show_D1(); // Викликаємо show() для D1
        cout << "D2::d3 = " << d3 << endl << endl;
    }
};
