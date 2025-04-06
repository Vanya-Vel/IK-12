#pragma once
#include <iostream>
#include <string>
using namespace std;

class Rectangle {
public:
    class Pair {  // �������� ����
    private:
        int first, second;
        static int counter;  // ˳������� ��'���� Pair

    public:
        Pair();  // ����������� ��� ���������
        Pair(int first, int second);  // ����������� � �����������
        Pair(const Pair& p);  // ����������� ���������
        ~Pair(void);  // ����������

        static int getCounter() {
            return counter;
        }  // ����� ��� ��������� ������� ��'���� Pair

        // �������� �������
        int getFirst() const { return first; }
        void setFirst(int first) { this->first = first; }
        int getSecond() const { return second; }
        void setSecond(int second) { this->second = second; }

        // ����� ��� ���������� �������
        int multiply() const { return first * second; }

        // �������� �� ���������
        friend istream& operator>>(istream& in, Pair& p);
        friend ostream& operator<<(ostream& out, const Pair& p);

        // ������������ � �����
        string toString() const;

        // �������� ���������� �� ����������
        Pair& operator++();  // �������
        Pair operator++(int);  // ��������
        Pair& operator--();  // �������
        Pair operator--(int);  // ��������
    };

private:
    Pair sides;  // ������������ Pair ��� ���������� �����
    static int counter;  // ˳������� ��'���� Rectangle

public:
    Rectangle();  // ����������� ��� ���������
    Rectangle(const Pair& sides);  // ����������� � �����������
    Rectangle(const Rectangle& r);  // ����������� ���������
    ~Rectangle(void);  // ����������

    static int getCounter() {
        return counter;
    }// ����� ��� ��������� ������� ��'���� Rectangle

    // ������ �������
    Pair getPair() const { return sides; }
    void setPair(const Pair& sides) { this->sides = sides; }

    // ���������� ��������� �� �����
    int getPerimeter() const {
        return 2 * (sides.getFirst() + sides.getSecond());
    }
    int getArea() const { return sides.multiply(); }

    // �������� ���������
    Rectangle& operator=(const Rectangle& r);

    // �������� ���������� �� ����������
    Rectangle& operator++();  // �������
    Rectangle operator++(int);  // ��������
    Rectangle& operator--();  // �������
    Rectangle operator--(int);  // ��������

    // �������� �� ���������
    friend ostream& operator<<(ostream& out, const Rectangle& r);
    friend istream& operator>>(istream& in, Rectangle& r);

    // ������������ � �����
    string toString() const;
};
