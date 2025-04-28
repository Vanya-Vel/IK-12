#pragma once
#include <iostream>
#include <functional>
#include <list>  // ������ ������ ������������� �������������� ������
using namespace std;

class Rand
{
public:
    // ���������� ���� ����� ��� �������� ������������
    using value_type = pair<double, double>;  // ��� ���� (x, p), �� x � ��������, p � ���������
    using size_type = size_t;                // ��� ��� ��������� ������ (������� ��������)
    using iterator = list<value_type>::iterator;  // �������� ��� ��������������� ������

private:
    list<value_type> data;  // �������������� ������ ��� ��������� ��� (x, p) ������ ������

public:
    // ����������� �� �������������
    Rand();
    // ����������� ���������
    Rand(const Rand& other);
    // �������� ���������
    Rand& operator=(const Rand& other);
    // ���������� (�� �������, ������� ������������� ��������� STL)
    ~Rand() = default;

    // ����� ��� ��������� ���� (x, p) � ������
    void add(double x, double p);
    // ����� ��� �������� ������
    void clear();

    // ����� ��� ���������� ������������� ����������
    double mean() const;
    // ����� ��� ���������� �������
    double variance() const;

    // ����� ��� ���������� ��������� ������� f(x) ������� �����-�����
    double monteCarloIntegral(function<double(double)> f, double a, double b, size_type N) const;

    // ����� ��� ��������� ����� ������ (��� x, p)
    void print() const;
    // ����� ��� ��������� ������� �������� � ������
    size_type size() const;

    // ������ ��� ��������� ���������
    iterator begin() { return data.begin(); }  // ������������� ��������� ��� ������� �� �������� ������
    iterator end() { return data.end(); }      // ��������� �������� ���������� ��� ������� �� ��������
};
