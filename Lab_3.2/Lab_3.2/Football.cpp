
#include "Football.h"

// ����������� �� �����������
Football::Football(string n, int p, string l)
    : SportGame(n, p), league(l) {}

// ����������� ���������
Football::Football(const Football& other)
    : SportGame(other), league(other.league) {}

// �������� ���������
Football& Football::operator=(const Football& other) {
    if (this != &other) {
        SportGame::operator=(other);
        league = other.league;
    }
    return *this;
}

// ��������� ���������� ��� ������
void Football::display(ostream& os) const {
    SportGame::display(os);
    os << ", ˳��: " << league;
}

// �������� ���������� � ������
void Football::input(istream& is) {
    SportGame::input(is);
    is >> league;
}
