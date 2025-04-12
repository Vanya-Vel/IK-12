#pragma once
#include "B1.h"
#include "B2.h"

class D1 : public B1, private B2
{
    int d1;
    int d2;

public:
    D1(int x, int y, int z) : B1(x), B2(y), d1(x), d2(y) {}

    ~D1() {}

    void show_D1()
    {
        cout << "class D1:" << endl;
        show_B1();  // Викликаємо show() для B1
        show_B2();  // Викликаємо show() для B2
        cout << "D1::d1 = " << d1 << endl;
        cout << "D1::d2 private = " << d2 << endl << endl;
    }
};
