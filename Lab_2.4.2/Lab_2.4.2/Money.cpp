#include "Money.h"
#include <iostream>
using namespace std;

Money::Money() {
    size = 3;        // Розмір масиву (3 елементи)
    count = 2;       // Два елементи для копійок (молодші дві цифри)

    if (size > MAX_SIZE) {
        cout << "Помилка: розмір перевищує MAX_SIZE!" << std::endl;
        size = MAX_SIZE;
    }

    // Ініціалізація всіх елементів масиву значенням 0
    for (size_t i = 0; i < size; i++) {
        summa[i] = 0;  // 0 для кожної цифри
    }
}

Money::Money(size_t S, size_t v)
{   // (розмір, стале значення всіх елементів)
    size = S;        // Розмір масиву (3 елементи)

    if (size > MAX_SIZE) {
        cout << "Помилка: розмір перевищує MAX_SIZE!" << std::endl;
        size = MAX_SIZE;
    }

    // Ініціалізація всіх елементів масиву
    for (size_t i = 0; i < size; i++) {
        summa[i] = v;
    }
}

Money::Money(const Money& other) {
    size = other.size;
    count = other.count;

    for (size_t i = 0; i < other.size; i++) {
        summa[i] = other.summa[i];
    }
}

Money Money::operator = (const Money& other)
{
    if (this != &other) {  // Перевірка на самоприсвоєння
        size = other.size;
        count = other.count;

        for (size_t i = 0; i < size; i++) {
            summa[i] = other.summa[i];
        }
    }
    return *this;
}

string Money::toString() const {

    int integerPart = 0;
    int fractionalPartInt = 0;
    
    for (size_t i = 0; i < 2; i++) {
        fractionalPartInt += summa[i] * pow(10, i);  // Складаємо цифри в число
    }
    for (size_t i = 2; i < size; i++) {
        integerPart += summa[i] * pow(10, i - 2);  // Складаємо цифри в число
    }

    const string ones[] = { "нуль", "один", "два", "три", "чотири", "п’ять", "шість", "сім", "вісім", "дев’ять" };
    const string teens[] = { "десять", "одинадцять", "дванадцять", "тринадцять", "чотирнадцять", "п’ятнадцять", "шістнадцять", "сімнадцять", "вісімнадцять", "дев’ятнадцять" };
    const string tens[] = { "", "десять", "двадцять", "тридцять", "сорок", "п’ятдесят", "шістдесят", "сімдесят", "вісімдесят", "дев’яносто" };
    const string hundreds[] = { "", "сто", "двісті", "триста", "чотириста", "п’ятсот", "шістсот", "сімсот", "вісімсот", "дев’ятсот" };

    string result = "";

    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (onesPart == 0) result += ones[0] + " ";
    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";
    else if (onesPart > 0) result += ones[onesPart] + " ";

    if (integerPart == 1) result += "гривня";
    else if (integerPart == 2  || integerPart == 3 || integerPart == 4) result += "гривні";
    else result += "гривень";

    if (fractionalPartInt > 0) {
        result += " , ";
        int kopTensPart = fractionalPartInt / 10;
        int kopOnesPart = fractionalPartInt % 10;

        if (kopTensPart == 0) result += ones[0] + " ";
        if (kopTensPart == 1) result += teens[kopOnesPart] + " ";
        else {
            if (kopTensPart > 1) result += tens[kopTensPart] + " ";
            if (kopOnesPart > 0) result += ones[kopOnesPart] + " ";
        }

        if (fractionalPartInt == 1) result += "одна сота";
        else if (fractionalPartInt == 2 || fractionalPartInt == 3 || fractionalPartInt == 4) result += "соті";
        else result += "сотих";
    }

    return result;
}

istream& operator >> (istream& in, Money& other) {
    cout << "Введіть розмір масиву: ";
    in >> other.size;

    if (other.size > other.MAX_SIZE) {
        cout << "Помилка: розмір перевищує MAX_SIZE! Автоматично встановлено " << other.MAX_SIZE << endl;
        other.size = other.MAX_SIZE;
    }

    cout << "Введіть " << other.size;
    if (other.size == 1)
    {
        cout << " значення: ";
    }
    else if (other.size >= 2 && other.size <= 4)
    {
        cout << " значення: ";
    }
    else cout << " значень: ";

    other.count = other.size;  // Встановлюємо count відповідно до size

    for (size_t i = 0; i < other.size; i++) {  // Цикл має йти до size, а не count
        in >> other.summa[i];
    }

    return in;
}

ostream& operator << (ostream& out, const Money& other) {
    out << "Масив розміром (" << other.size << "): ";
    for (size_t i = 0; i < other.size; i++) {  // Виведення всіх елементів
        out << other.summa[i] << " ";
    }
    return out;
}
