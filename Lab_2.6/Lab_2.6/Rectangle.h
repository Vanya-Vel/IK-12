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

        static int getCounter();  // ����� ��� ��������� ������� ��'���� Pair

        // �������� �������
        int getFirst() const;
        void setFirst(int first);
        int getSecond() const;
        void setSecond(int second);

        // ����� ��� ���������� �������
        int multiply() const;

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

    static int getCounter();  // ����� ��� ��������� ������� ��'���� Rectangle

    // ������ �������
    Pair getPair() const;
    void setPair(const Pair& sides);

    // ���������� ��������� �� �����
    int getPerimeter() const;
    int getArea() const;

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
