#pragma once
#include "SportGame.h"

// �������� ���� "������"
class Football : public SportGame {
private:
    string league;    // ����� ���

public:
    Football(string n = "", int p = 0, string l = "");   // �����������
    Football(const Football& other);                     // ����������� ���������
    Football& operator=(const Football& other);          // �������� ���������
    void display(ostream& os) const;                     // ���������
    void input(istream& is);                             // ��������
};
