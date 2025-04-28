#pragma once
#include "A.h"

class B : public A {
public:
    B() { std::cout << "����������� B" << std::endl; }

    // �����, �� ������ ���� ��'���� ����� A
    void copyAndProcess(const A& a) {
        try {
            // ������ �������� �� ���� B
            const B& b = dynamic_cast<const B&>(a); // �������� ���������� ����
            std::cout << "��������� �� ���� B.\n";
            b.display();
        }
        catch (const std::bad_cast& e) {
            // ������� �������, ���� ���������� ���� ���������
            std::cout << "������� ���������� ����: " << e.what() << std::endl;
        }
    }

    void display() const override {
        std::cout << "���� B" << std::endl;
    }
};

