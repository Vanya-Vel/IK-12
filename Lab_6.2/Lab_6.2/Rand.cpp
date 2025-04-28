#include "Rand.h"
#include <stdexcept>
#include <random>
#include <cmath>

// �����������, �������� ������� �������� �� ������ ������
Rand::Rand(size_type cap) : count(0), capacity(cap)
{
    data = new value_type[capacity];  // ���������� ���'��� ��� ������
}

// ����������� ���������
Rand::Rand(const Rand& other) : count(other.count), capacity(other.capacity)
{
    data = new value_type[capacity];  // ���������� ���'��� ��� ������ ������
    for (size_type i = 0; i < count; ++i)
        data[i] = other.data[i];  // ��������� ��� � ������ ��'����
}

// �������� ���������
Rand& Rand::operator=(const Rand& other)
{
    if (this != &other)  // �������� �� �������������
    {
        delete[] data;  // ��������� ���������� ������� ���'��
        capacity = other.capacity;  // ��������� ������
        count = other.count;  // ��������� ������� ��������
        data = new value_type[capacity];  // �������� ���'�� ��� ������ ������
        for (size_type i = 0; i < count; ++i)
            data[i] = other.data[i];  // ��������� �����
    }
    return *this;  // ���������� ��������� ��'����
}

// ����������
Rand::~Rand()
{
    delete[] data;  // ��������� ���'��, ������� �� �����
}

// ����� ��� ��������� ���� (x, p) � �����
void Rand::add(double x, double p)
{
    if (p < 0.0)
        throw invalid_argument("��������� �� ���� ���� ��'�����.");  // �������� �� ��'���� ���������

    if (count >= capacity)
        throw overflow_error("���������� ������� ������.");  // �������� �� ����������� ������� ������

    data[count++] = { x, p };  // ��������� ���� � �����
}

// ����� ��� �������� ������
void Rand::clear()
{
    count = 0;  // �������� ������ (��������� ������� ��������)
}

// ����� ��� ���������� ������������� ����������
double Rand::mean() const
{
    double sum = 0.0;
    for (size_type i = 0; i < count; ++i)
        sum += data[i].first * data[i].second;  // ϳ������������ x * p ��� ����� ����
    return sum;  // ����������� ����������� ����������
}

// ����� ��� ���������� �������
double Rand::variance() const
{
    double m = mean();  // ����������� ����������
    double sum = 0.0;
    for (size_type i = 0; i < count; ++i)
        sum += (data[i].first - m) * (data[i].first - m) * data[i].second;  // ϳ������������ (x - m)^2 * p
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
    for (size_type i = 0; i < count; ++i)
        cout << "(" << data[i].first << ", " << data[i].second << ")" << endl;  // ��������� ��� (x, p)
}

// ����� ��� ��������� ������� �������� � �����
Rand::size_type Rand::size() const
{
    return count;  // ����������� ������� �������� � �����
}
