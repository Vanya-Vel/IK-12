#pragma once
#include <iostream>
#include <string>
using namespace std;

// ������� ���� "��������� ���"
class SportGame {
protected:
    string name;         // ����� ���
    int playersCount;    // ʳ������ �������

public:
    SportGame(string n = "", int p = 0);                // �����������
    SportGame(const SportGame& other);                  // ����������� ���������
    SportGame& operator=(const SportGame& other);       // �������� ���������
    bool operator==(const SportGame& other) const;  // ������� ��� �������� � ���������
    void display(ostream& os) const;                    // ���������
    void input(istream& is);                            // ��������
};
