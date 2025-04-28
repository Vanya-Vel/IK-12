#include "Functions.h"
#include <iostream>

using namespace std;

double Functions::distanceFromXtoY(const Functions& other) const {
    double dist = sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));

    double rounded = round(dist * 100) / 100;

    return rounded;
}

string Functions::toString(const Functions& other) const {
    try {
        double dist = distanceFromXtoY(other);
        return ToNumeral(dist);
    }
    catch (const PointException& ex) {
        return ex.what();  // ¬иведенн€ помилки у випадку вин€тку
    }
}

string Functions::ToNumeral(double amount) const {
    int integerPart = static_cast<int>(amount); // ќтримуЇмо ц≥лу частину
    int fractionalPartInt = static_cast<int>(round((amount - integerPart) * 100)); // ќкруглюЇмо коп≥йки до 2 знак≥в

    const string ones[] = { "", "один", "два", "три", "чотири", "пТ€ть", "ш≥сть", "с≥м", "в≥с≥м", "девТ€ть" };
    const string teens[] = { "дес€ть", "одинадц€ть", "дванадц€ть", "тринадц€ть", "чотирнадц€ть", "пТ€тнадц€ть", "ш≥стнадц€ть", "с≥мнадц€ть", "в≥с≥мнадц€ть", "девТ€тнадц€ть" };
    const string tens[] = { "", "дес€ть", "двадц€ть", "тридц€ть", "сорок", "пТ€тдес€т", "ш≥стдес€т", "с≥мдес€т", "в≥с≥мдес€т", "девТ€носто" };
    const string hundreds[] = { "", "сто", "дв≥ст≥", "триста", "чотириста", "пТ€тсот", "ш≥стсот", "с≥мсот", "в≥с≥мсот", "девТ€тсот" };

    string result = "";

    // ќбробка ц≥лоњ частини
    int hundredsPart = integerPart / 100;
    int tensPart = (integerPart % 100) / 10;
    int onesPart = integerPart % 10;

    if (hundredsPart > 0) result += hundreds[hundredsPart] + " ";
    if (tensPart > 1) result += tens[tensPart] + " ";
    if (tensPart == 1) result += teens[onesPart] + " ";
    else if (onesPart > 0) result += ones[onesPart] + " ";

    if (integerPart == 1) result += "одиниц€";
    else if (integerPart >= 2 && integerPart <= 4) result += "одиниц≥";
    else result += "одиниць";

    // ќбробка коп≥йок
    if (fractionalPartInt > 0) {
        result += " , ";

        if (fractionalPartInt % 10 == 0) {  // якщо число кратне 10 (10, 20, 30...)
            int dec = fractionalPartInt / 10;
            if (dec == 1) result += "одна дес€та";
            else if (dec == 2) result += "дв≥ дес€т≥";
            else result += ones[dec] + " дес€тих";
        }
        else {
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
    }

    return result;
}