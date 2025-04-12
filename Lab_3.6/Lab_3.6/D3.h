#pragma once
#include "D2.h"

class D3 : public D2
{
    int d4;

public:
    D3(int x, int y, int z, int w) : D2(x, y, z), d4(w) {}

    ~D3() {}

    void show_D3()
    {
        cout << "class D3:" << endl;
        show_D2(); // Викликаємо show() для D2
        cout << "D3::d4 = " << d4 << endl << endl;
    }
};
