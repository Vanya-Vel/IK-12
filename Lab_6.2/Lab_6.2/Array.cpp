#include "Array.h"

// ����������� ��� ���������
Array::Array() throw(bad_alloc) : size_array(minsize), Count(0), First(0), data(nullptr) {
    data = new value_type[size_array];  // �������� ���'��
}

// ����������� � ����� ����������
Array::Array(const size_type n) throw(bad_alloc) : size_array(n), Count(n), First(0), data(nullptr) {
    data = new value_type[size_array];  // �������� ���'��
}

// ����������� � ����� �����������
Array::Array(const iterator first, const iterator last) throw(bad_alloc, invalid_argument) {
    if (first <= last) {
        Count = size_array = (last - first) + 1;
        data = new value_type[size_array];  // �������� ���'��
        for (UINT i = 0; i < size_array; ++i) {
            data[i] = *(first + i);
        }
    }
    else {
        throw invalid_argument("Invalid range for iterators!");
    }
}

// ����������� ���������
Array::Array(const Array& t) throw(bad_alloc) : size_array(t.size_array), Count(t.Count), First(t.First) {
    data = new value_type[size_array];  // �������� ���'��
    for (UINT i = 0; i < size_array; ++i) {
        data[i] = t.data[i];  // ��������� ��������
    }
}

// ����������
Array::~Array() {
    delete[] data;
}

// �������� ���������
Array& Array::operator=(const Array& rhs) throw(bad_alloc) {
    if (this != &rhs) {
        size_array = rhs.size_array;
        Count = rhs.Count;
        First = rhs.First;

        value_type* new_data = new value_type[size_array];  // �������� ���� ���'��
        for (UINT i = 0; i < size_array; ++i) {
            new_data[i] = rhs.data[i];  // ��������� ��������
        }

        delete[] data;
        data = new_data;
    }
    return *this;
}

// �������� ������������ (�������� �� ���������� �������)
Array::reference Array::operator[](UINT index) throw(out_of_range) {
    if (index < size_array) {
        return data[index];
    }
    else {
        throw out_of_range("Index out of range!");
    }
}

Array::const_reference Array::operator[](UINT index) const throw(out_of_range) {
    if (index < size_array) {
        return data[index];
    }
    else {
        throw out_of_range("Index out of range!");
    }
}

// ����� ������
Array::UINT Array::size() const {
    return size_array;
}

// ���������
Array::iterator Array::begin() {
    return data;
}

Array::const_iterator Array::begin() const {
    return data;
}

Array::iterator Array::end() {
    return data + Count;
}

Array::const_iterator Array::end() const {
    return data + Count;
}

// �������� �����/������
ostream& operator<<(ostream& out, const Array& a) {
    for (size_t j = 0; j < a.size_array; j++) {
        out << a.data[j] << " ";
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, Array& a) {
    for (size_t i = 0; i < a.size_array; i++) {
        in >> a.data[i];
    }
    return in;
}
