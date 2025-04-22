#pragma once

class Currency {
protected:
    static double courseD;  // Курс долара
    static double courseE;  // Курс євро

public:
    virtual double Exchange(double n) const = 0;  // Переведення в гривні
    virtual void ExchangeDisplay(double n) const = 0;  // Виведення на екран
    virtual ~Currency() = default;
};
