#pragma once
#include <iostream>
#include <functional>
using namespace std;

class Rand
{
public:
    // ���������� ���� ����� ��� �������� ������������
    using value_type = pair<double, double>;  // ��� ���� (x, p), �� x � ��������, p � ���������
    using size_type = size_t;                // ��� ��� ��������� ������ (������� ��������)

private:
    value_type* data;       // ����� ��� (x, p), �� ��������� �������� �� ���������
    size_type count;        // ʳ������ �������� � �����
    size_type capacity;     // ������ ������ (����������� ������� ��������, ��� �� ���� ��������)

public:
    // ����������� � ���������� �� ������� ��������
    Rand(size_type cap = 10);
    // ����������� ���������
    Rand(const Rand& other);
    // �������� ���������
    Rand& operator=(const Rand& other);
    // ���������� ��� �������� ���'��
    ~Rand();

    // ����� ��� ��������� ���� (x, p) � �����
    void add(double x, double p);
    // ����� ��� �������� ������ (��������� ��� ��������)
    void clear();

    // ����� ��� ���������� ������������� ����������
    double mean() const;
    // ����� ��� ���������� �������
    double variance() const;

    // ����� ��� ���������� ��������� ������� f(x) ������� �����-�����
    double monteCarloIntegral(function<double(double)> f, double a, double b, size_type N) const;

    // ����� ��� ��������� ����� ������ (��� x, p)
    void print() const;
    // ����� ��� ��������� ������� �������� � �����
    size_type size() const;
};
