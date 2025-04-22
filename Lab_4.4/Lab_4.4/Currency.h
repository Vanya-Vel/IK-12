#pragma once

class Currency {
protected:
    static double courseD;  // ���� ������
    static double courseE;  // ���� ����

public:
    virtual double Exchange(double n) const = 0;  // ����������� � �����
    virtual void ExchangeDisplay(double n) const = 0;  // ��������� �� �����
    virtual ~Currency() = default;
};
