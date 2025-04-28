#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <exception>
using namespace std;

// ����������� � �������
Array::Array(const Array::size_type& n) throw(bad_alloc, invalid_argument)
{
    First = 0;
    Count = Size = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0;
}

// ����������� � ��������� ���������
Array::Array(const iterator first, const iterator last) throw(bad_alloc, invalid_argument)
{
    First = 0;
    if (first <= last) {
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("������������ ������� ���������!");
}

// ����������� � ������� � ���������� �������
Array::Array(const size_type first, const size_type last) throw(bad_alloc, invalid_argument)
{
    if (first <= last) {
        First = first;
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("������������ ������� �������!");
}

// ����������� ���������
Array::Array(const Array& t) throw(bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
    for (UINT i = 0; i < Size; ++i)
        elems[i] = t.elems[i];
}

// �������� ���������
Array& Array::operator=(const Array& t)
{
    Array tmp(t);
    swap(tmp);
    return *this;
}

// ����������
Array::~Array()
{
    delete[] elems;
    elems = 0;
}

// ��������� �������� � �����
void Array::push_back(const value_type& v)
{
    if (Count == Size)
        resize(Size * 2);
    elems[Count++] = v;
}

// ��������� ������� �������� (��������� ����������)
void Array::pop_back()
{
    if (Count > 0)
        --Count;
    else
        throw underflow_error("����� �������!");
}

// ������ �� �������� �� ��������
Array::reference Array::operator[](size_type index) throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("������ ���� ���������!");
}

// ����������� ������ �� ��������
Array::const_reference Array::operator[](size_type index) const throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("������ ���� ���������!");
}

// ���� ������ ������
void Array::resize(size_type newsize) throw(bad_alloc)
{
    if (newsize > capacity())
    {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

// ���� ��������
void Array::swap(Array& other)
{
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
    std::swap(Count, other.Count);
    std::swap(First, other.First);
}

// �������� �������
Array::size_type Array::capacity() const
{
    return Size;
}

// �������� �������� �����
Array::size_type Array::size() const
{
    return Count;
}

// �������� �� �������
bool Array::empty() const
{
    return Count == 0;
}

// �������� ������
istream& operator>>(istream& in, Array& tmp)
{
    for (size_t i = 0; i < tmp.Count; ++i)
        in >> tmp.elems[i];
    return in;
}

// ��������� ������
ostream& operator<<(ostream& out, const Array& tmp)
{
    for (size_t j = 0; j < tmp.Count; j++)
        out << tmp[j] << " ";
    out << endl;
    return out;
}

// ���������� ������ ������ ���������
void Array::assign(const value_type& v)
{
    for (size_type i = 0; i < Size; ++i)
        elems[i] = v;
}

// ��������� ������� ������� ������
Array Array::MultiplyByMinimum(const Array::value_type* inputArray, int size)
{
    if (size <= 0)
        throw invalid_argument("����� ������ ������� ���� �������!");

    // ��������� ��'���� Array
    Array result(size);

    // ������� ����� ���
    for (int i = 0; i < size; ++i)
        result[i] = inputArray[i];

    // ����� ���������� �������� � �����
    double minVal = result[0];  // ����������� ���������� ��������

    for (int i = 1; i < size; ++i)  // �������� � ������� ��������, ������� ������ ��� ������
    {
        if (result[i] < minVal)
            minVal = result[i];  // ��������� ��������� �������
    }

    cout << "̳�������� �������: " << minVal << endl;  // ������� ��������� ������� ��� ��������

    // ������� �� �������� �� ��������� �������
    for (int i = 0; i < size; ++i)
        result[i] *= minVal;

    return result;
}

