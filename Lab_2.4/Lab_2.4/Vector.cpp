#include "Vector.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

Vector::Vector() {
    size = 1;
    count = 1;
    N = 1;
    data[0] = N;
}

Vector::Vector(size_t n, int N) {
    size = n;
    count = n;

    if (size > MAX_SIZE) {
        cout << "Помилка: розмір перевищує MAX_SIZE!" << std::endl;
        size = MAX_SIZE;
    }
    for (size_t i = 0; i < count; i++) {
        data[i] = N;
    }
}

Vector::Vector(const Vector& other) {
    size = other.size;
    count = other.count;
    N = other.N;

    for (size_t i = 0; i < count; i++) {
        data[i] = other.data[i];
    }
}

double Vector::NormVector() const {
    double sum = 0;
    for (size_t i = 0; i < count; i++) {  // має бути count, не size
        sum += data[i] * data[i];
    }
    return sqrt(sum);
}

string Vector::toString(double num) const {
    int integerPart = static_cast<int>(num);
    int fractionalPartInt = static_cast<int>(round((num - integerPart) * 100));

    const string ones[] = { "", "один", "два", "три", "чотири", "п’ять", "шість", "сім", "вісім", "дев’ять" };
    const string teens[] = { "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п’ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев’ятнадцять" };
    const string tens[] = { "", "десять", "двадцять", "тридцять", "сорок", "п’ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев’яносто" };
    const string hundreds[] = { "", "сто", "двісті", "триста", "чотириста", "п’ятсот", "шістсот", "сімсот", "вісімсот", "дев’ятсот" };

    string result = "";

    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";
    else if (onesPart > 0) result += ones[onesPart] + " ";

    if (integerPart == 1) result += "одиниця";
    else if (integerPart >= 2 && integerPart <= 4) result += "одиниці";
    else result += "одиниць";

    if (fractionalPartInt > 0) {
        result += " , ";
        int kopTensPart = fractionalPartInt / 10;
        int kopOnesPart = fractionalPartInt % 10;

        if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
        else {
            if (kopTensPart > 1) result += tens[kopTensPart] + " ";
            if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";
        }

        if (fractionalPartInt == 1) result += "одна сотих";
        else if (fractionalPartInt >= 2 && fractionalPartInt <= 4) result += "сотих";
        else result += "сотих";
    }

    return result;
}

Vector Vector::operator * (const Vector& other) {
    Vector result(other.size, other.N);

    size_t minSize = (count < other.count) ? count : other.count;
    for (size_t i = 0; i < minSize; i++) {
        result.data[i] = data[i] * other.data[i];
    }

    return result;
}

int Vector::summa()
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum;
}

bool Vector::operator == (const Vector& other) const {
    // Якщо розміри векторів різні — вони не рівні
    if (size != other.size || count != other.count) {
        return false;
    }

    // Порівнюємо кожен елемент
    for (size_t i = 0; i < count; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true; // Якщо всі елементи збігаються, вектори рівні
}

// Префіксний інкремент (++v)
Vector& Vector::operator++() {
    for (size_t i = 0; i < count; i++) {
        data[i]++;
    }
    return *this;
}

// Постфіксний інкремент (v++)
Vector Vector::operator++(int) {
    Vector temp = *this;  // Зберігаємо поточний стан
    ++(*this);            // Викликаємо префіксний оператор
    return temp;          // Повертаємо початковий стан
}

// Префіксний декремент (--v)
Vector& Vector::operator--() {
    for (size_t i = 0; i < count; i++) {
        data[i]--;
    }
    return *this;
}

// Постфіксний декремент (v--)
Vector Vector::operator--(int) {
    Vector temp = *this;  // Зберігаємо поточний стан
    --(*this);            // Викликаємо префіксний оператор
    return temp;          // Повертаємо початковий стан
}

ostream& operator << (ostream& out, const Vector& other)
{
    out << "Вектор розміром (" << other.size << "): ";
    for (size_t i = 0; i < other.count; i++) {
        out << other.data[i] << " ";
    }
    return out;
}

istream& operator >> (istream& in, Vector& other)
{
    cout << "Введіть розмір вектора: ";
    in >> other.size;

    if (other.size > other.MAX_SIZE) {
        cout << "Помилка: розмір перевищує MAX_SIZE! Автоматично встановлено " << other.MAX_SIZE << endl;
        other.size = other.MAX_SIZE;
    }

    cout << "Введіть " << other.size << " значень: ";
    other.count = other.size;  // Встановлюємо count відповідно до size

    for (size_t i = 0; i < other.count; i++) {
        in >> other.data[i];
    }

    return in;
}
