#include "Rand.h"
#include <stdexcept>
#include <random>
#include <cmath>

// ����������� �� �������������
Rand::Rand() = default;

// ����������� ���������
Rand::Rand(const Rand & other) : data(other.data) {}

// �������� ���������
Rand& Rand::operator=(const Rand & other)
{
    if (this != &other)  // �������� �� �������������
    {
        data = other.data;  // ��������� ���� ������
    }
    return *this;  // ���������� ��������� ��'����
}

// ����� ��� ��������� ���� (x, p) � ������
void Rand::add(double x, double p)
{
    if (p < 0.0)
        throw invalid_argument("��������� �� ���� ���� ��'�����.");  // �������� �� ��'���� ���������

    data.push_back({ x, p });  // ��������� ���� � ����� ������
}

// ����� ��� �������� ������
void Rand::clear()
{
    data.clear();  // �������� ������
}

// ����� ��� ���������� ������������� ����������
double Rand::mean() const
{
    double sum = 0.0;
    for (const auto& pair : data)
        sum += pair.first * pair.second;  // ϳ������������ x * p ��� ����� ����
    return sum;  // ����������� ����������� ����������
}

// ����� ��� ���������� �������
double Rand::variance() const
{
    double m = mean();  // ����������� ����������
    double sum = 0.0;
    for (const auto& pair : data)
        sum += (pair.first - m) * (pair.first - m) * pair.second;  // ϳ������������ (x - m)^2 * p
    return sum;  // ����������� ��������
}

// ����� ��� ���������� ��������� ������� f(x) ������� �����-�����
double Rand::monteCarloIntegral(function<double(double)> f, double a, double b, size_type N) const
{
    if (a >= b || N == 0)
        throw invalid_argument("��������� ��������� ��� ������������.");  // �������� �� ���������� ���������

    random_device rd;  // ����������� ����������� ����������
    mt19937 gen(rd());  // ��������� ���������� �����
    uniform_real_distribution<> dis(a, b);  // ������� ��� ���������� ����� � ����� [a, b]

    double sum = 0.0;
    for (size_type i = 0; i < N; ++i)
    {
        double x = dis(gen);  // ��������� ��������� �����
        sum += f(x);  // ���������� �������� ������� � ����� x
    }
    return (b - a) * sum / static_cast<double>(N);  // ���������� �� ���������� ���������
}

// ����� ��� ��������� ����� ������ (��� x, p)
void Rand::print() const
{
    for (const auto& pair : data)
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;  // ��������� ��� (x, p)
}

// ����� ��� ��������� ������� �������� � ������
Rand::size_type Rand::size() const
{
    return data.size();  // ����������� ������� �������� � ������
}
