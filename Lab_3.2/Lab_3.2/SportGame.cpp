
#include "SportGame.h"

// ����������� �� �����������
SportGame::SportGame(string n, int p) : name(n), playersCount(p) {}

// ����������� ���������
SportGame::SportGame(const SportGame& other) {
    name = other.name;
    playersCount = other.playersCount;
}

// �������� ���������
SportGame& SportGame::operator=(const SportGame& other) {
    if (this != &other) {
        name = other.name;
        playersCount = other.playersCount;
    }
    return *this;
}

// �������� ���������
bool SportGame::operator==(const SportGame& other) const {
    return name == other.name && playersCount == other.playersCount;
}

// ��������� ���������� ��� ���
void SportGame::display(ostream& os) const {
    os << "��������� ���: " << name << ", �������: " << playersCount;
}

// �������� ���������� � ������
void SportGame::input(istream& is) {
    is >> name >> playersCount;
}
